;; Auto-generated. Do not edit!


(when (boundp 'publisher_pkg::theRandomNum)
  (if (not (find-package "PUBLISHER_PKG"))
    (make-package "PUBLISHER_PKG"))
  (shadow 'theRandomNum (find-package "PUBLISHER_PKG")))
(unless (find-package "PUBLISHER_PKG::THERANDOMNUM")
  (make-package "PUBLISHER_PKG::THERANDOMNUM"))

(in-package "ROS")
;;//! \htmlinclude theRandomNum.msg.html


(defclass publisher_pkg::theRandomNum
  :super ros::object
  :slots (_data ))

(defmethod publisher_pkg::theRandomNum
  (:init
   (&key
    ((:data __data) 0.0)
    )
   (send-super :init)
   (setq _data (float __data))
   self)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; float32 _data
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _data
       (sys::poke _data (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _data
     (setq _data (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get publisher_pkg::theRandomNum :md5sum-) "73fcbf46b49191e672908e50842a83d4")
(setf (get publisher_pkg::theRandomNum :datatype-) "publisher_pkg/theRandomNum")
(setf (get publisher_pkg::theRandomNum :definition-)
      "float32 data
")



(provide :publisher_pkg/theRandomNum "73fcbf46b49191e672908e50842a83d4")


