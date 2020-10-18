;; Auto-generated. Do not edit!


(when (boundp 'topic_pkg::range)
  (if (not (find-package "TOPIC_PKG"))
    (make-package "TOPIC_PKG"))
  (shadow 'range (find-package "TOPIC_PKG")))
(unless (find-package "TOPIC_PKG::RANGE")
  (make-package "TOPIC_PKG::RANGE"))

(in-package "ROS")
;;//! \htmlinclude range.msg.html


(defclass topic_pkg::range
  :super ros::object
  :slots (_number ))

(defmethod topic_pkg::range
  (:init
   (&key
    ((:number __number) 0)
    )
   (send-super :init)
   (setq _number (round __number))
   self)
  (:number
   (&optional __number)
   (if __number (setq _number __number)) _number)
  (:serialization-length
   ()
   (+
    ;; int16 _number
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _number
       (write-word _number s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _number
     (setq _number (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get topic_pkg::range :md5sum-) "6500e1e658110ec1daa9475082592be3")
(setf (get topic_pkg::range :datatype-) "topic_pkg/range")
(setf (get topic_pkg::range :definition-)
      "int16 number

")



(provide :topic_pkg/range "6500e1e658110ec1daa9475082592be3")


