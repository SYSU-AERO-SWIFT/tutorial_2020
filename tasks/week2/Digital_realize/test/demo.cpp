#include"NumRec.h"

int main(int argc, char** argv)
{
	if(argc==1){
	cout<<"请输入图片路径"<<endl;
	}
	else if(argc==2){
	NumRec digit(argv[1]);
	digit.numGet();
	}
	else if(argc==3){
	NumRec digit(argv[1],argv[2]);
	digit.numGet();
	}
	
	cout<<endl;	

	waitKey(0);
	return 0;

}

