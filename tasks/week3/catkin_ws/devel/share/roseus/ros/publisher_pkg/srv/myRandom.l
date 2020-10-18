;; Auto-generated. Do not edit!


(when (boundp 'publisher_pkg::myRandom)
  (if (not (find-package "PUBLISHER_PKG"))
    (make-package "PUBLISHER_PKG"))
  (shadow 'myRandom (find-package "PUBLISHER_PKG")))
(unless (find-package "PUBLISHER_PKG::MYRANDOM")
  (make-package "PUBLISHER_PKG::MYRANDOM"))
(unless (find-package "PUBLISHER_PKG::MYRANDOMREQUEST")
  (make-package "PUBLISHER_PKG::MYRANDOMREQUEST"))
(unless (find-package "PUBLISHER_PKG::MYRANDOMRESPONSE")
  (make-package "PUBLISHER_PKG::MYRANDOMRESPONSE"))

(in-package "ROS")





(defclass publisher_pkg::myRandomRequest
  :super ros::object
  :slots (_random_num ))

(defmethod publisher_pkg::myRandomRequest
  (:init
   (&key
    ((:random_num __random_num) 0.0)
    )
   (send-super :init)
   (setq _random_num (float __random_num))
   self)
  (:random_num
   (&optional __random_num)
   (if __random_num (setq _random_num __random_num)) _random_num)
  (:serialization-length
   ()
   (+
    ;; float32 _random_num
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _random_num
       (sys::poke _random_num (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _random_num
     (setq _random_num (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass publisher_pkg::myRandomResponse
  :super ros::object
  :slots (_judge ))

(defmethod publisher_pkg::myRandomResponse
  (:init
   (&key
    ((:judge __judge) nil)
    )
   (send-super :init)
   (setq _judge __judge)
   self)
  (:judge
   (&optional __judge)
   (if __judge (setq _judge __judge)) _judge)
  (:serialization-length
   ()
   (+
    ;; bool _judge
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _judge
       (if _judge (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _judge
     (setq _judge (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass publisher_pkg::myRandom
  :super ros::object
  :slots ())

(setf (get publisher_pkg::myRandom :md5sum-) "af3f1147d7daae631b82b1a427cd4a2f")
(setf (get publisher_pkg::myRandom :datatype-) "publisher_pkg/myRandom")
(setf (get publisher_pkg::myRandom :request) publisher_pkg::myRandomRequest)
(setf (get publisher_pkg::myRandom :response) publisher_pkg::myRandomResponse)

(defmethod publisher_pkg::myRandomRequest
  (:response () (instance publisher_pkg::myRandomResponse :init)))

(setf (get publisher_pkg::myRandomRequest :md5sum-) "af3f1147d7daae631b82b1a427cd4a2f")
(setf (get publisher_pkg::myRandomRequest :datatype-) "publisher_pkg/myRandomRequest")
(setf (get publisher_pkg::myRandomRequest :definition-)
      "float32 random_num
---
bool judge
")

(setf (get publisher_pkg::myRandomResponse :md5sum-) "af3f1147d7daae631b82b1a427cd4a2f")
(setf (get publisher_pkg::myRandomResponse :datatype-) "publisher_pkg/myRandomResponse")
(setf (get publisher_pkg::myRandomResponse :definition-)
      "float32 random_num
---
bool judge
")



(provide :publisher_pkg/myRandom "af3f1147d7daae631b82b1a427cd4a2f")


