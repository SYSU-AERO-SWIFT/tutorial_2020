#include<opencv2/opencv.hpp>
#include<cmath>
#include<vector>

using namespace cv;

//轮廓寻找
void findcontours(Mat& input, std::vector<std::vector<Point>>& contours, std::vector<Vec4i>& hierarchy)
{
	if(input.empty())
		return;
	//背景全设为0，前景全设为1
	Mat output(input.rows, input.cols, CV_32FC1, Scalar(0));
	output.setTo(Scalar(1), input);
	//设置一个用于查找的8邻域的核
	int kernel[8][2] = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1},
		{0, 1}, {-1, 1} };
	//当前轮廓序号和前几条轮廓序号
	int NBD = 1;
	int LNBD;
	int LLNBD;
	int LLLNBD;
	hierarchy.push_back(Vec4i(-1, -1, -1, -1));
	
	for(int i = 0; i < output.rows; i++)
	{
		LNBD = 1;
		LLNBD = 1;
		LLLNBD = 1;
		for(int j = 0; j < output.cols; j++)
		{
			//p0为轮廓起始点，p1为顺时针方向找到的第一个轮廓点，p2为水平方向最			     近的0值点
			Point2i p0(j, i);
			Point2i p1;
			Point2i p2;
			//由0变1，找到外部轮廓起始点
			if(output.at<float>(i, j) == 1 && output.at<float>(i, j-1) == 0)
			{
				NBD++;
				p2.x = j - 1;
				p2.y = i;
			}
			//由正值变0， 找到孔轮廓起始点
			else if(output.at<float>(i, j) >= 1 && 
					output.at<float>(i, j+1) == 0)
			{
				NBD++;
				p2.x = j + 1;
				p2.y = i;
				if(output.at<float>(p0) > 1)
				{
					LLLNBD = LLNBD;
					LLNBD = LNBD;
					LNBD = output.at<float>(p0);
				}	
			}
			//不是起始点，继续扫描
			else
			{
				if(output.at<float>(p0) != 1 && output.at<float>(p0) != LNBD)
				{
					LLLNBD = LLNBD;
					LLNBD = LNBD;
					LNBD = std::abs(output.at<float>(p0));
				}
				continue;
			}

			//确定p2的位置
			int k;
			for(k = 0; k < 8; k++)
			{
				if((p2.x - p0.x == kernel[k][0]) && 
						(p2.y - p0.y == kernel[k][1]))
					break;
			}
			
			//从p2点开始，在以p0为核心的8邻域按顺时针方向查找非零点p1
			bool found = false;

			for(int n = k; n < k + 8; n++)
			{
				int m = n % 8;
				if(output.at<float>((p0.y + kernel[m][1]),
							(p0.x + kernel[m][0])) != 0)
				{
					found = true;
					p1.x = p0.x + kernel[m][0];
					p1.y = p0.y + kernel[m][1];
					break;
				}
			}
								
			//未找到p1，继续扫描
			if(!found)
			{
				output.at<float>(p0) = -NBD;
				continue;
			}
			//找到p1，开始沿着轮廓查找
			else
			{
				Point2i p4 = p0;
				Point2i p3 = p1;
				//p2初始值为p1，p3初始值为p0
				//每次都以p3为核心，从p2开始查找非零值p4，直到回到轮廓起始 				     点
				do
				{
					p2 = p3;
					p3 = p4;
					int k;
					for(k = 0; k < 8; k++)
					{
						if((p2.x - p3.x == kernel[k][0]) && 
							     (p2.y - p3.y == kernel[k][1]))
							break;
					}

					int n;
					for(n = k - 1; n >= k - 8; n--)
					{
						int m = n;
						if(n < 0)
							m = n + 8;	
						if(output.at<float>((p3.y + kernel[m][1]),
							       (p3.x + kernel[m][0])) != 0)
						{
							p4.x = p3.x + kernel[m][0];
							p4.y = p3.y + kernel[m][1];
							break;
						}
					}
					
					if((k > 3 || n < -3) && output.at<float>((p3.y + 
						kernel[4][1]), (p3.x + kernel[4][0])) == 0)
						output.at<float>(p3) = -NBD;
					else if(output.at<float>(p3) == 1)
						output.at<float>(p3) = NBD;
				} while(p4.x != p0.x || p4.y != p0.y || 
						p3.x != p1.x || p3.y != p1.y);						
			}
		
		//记录继承关系
		int a, b;
		if(LNBD != 0)
		{
			if(LLNBD == 0)
			{
				hierarchy[LNBD - 1][2] = NBD - 1;
				b = LNBD - 1;
				a = -1;
			}
			else
			{
				a = LNBD - 1;
				b = hierarchy[LNBD - 1][3];
				hierarchy[LNBD - 1][0] = NBD - 1;
			}
		}
		else
		{
			if(LLLNBD != 0)
			{
				b = LLNBD - 1;
				a = -1;
				hierarchy[LLNBD - 1][2] = NBD - 1;
			}
			else
			{
				b = hierarchy[LLNBD - 1][3];
				a = LLNBD - 1;
				hierarchy[LLNBD - 1][0] = NBD - 1;
			}
		}

		hierarchy.push_back(Vec4i(-1, a, -1, b));

		if(output.at<float>(p0) != 1 && output.at<float>(p0) != LNBD)
		{
			LLLNBD = LLNBD;
			LLNBD = LNBD;
			LNBD = std::abs(output.at<float>(p0));
		}

		}
	}

	//存储轮廓点
	contours.resize(NBD);
	for(int i = 0; i < output.cols; i++)
	{
		for(int j = 0; j < output.rows; j++)
		{
			if(i == 0 || j == 0 || i == output.cols - 1 || j == input.rows - 1)
				contours[0].push_back(Point(i, j));
			else if(std::abs(output.at<float>(i, j)) > 1)
				contours[int(std::abs(output.at<float>(i, j)) - 1)].push_back(Point(i, j));
		}
	}
}
