;; Auto-generated. Do not edit!


(when (boundp 'service_pkg::number)
  (if (not (find-package "SERVICE_PKG"))
    (make-package "SERVICE_PKG"))
  (shadow 'number (find-package "SERVICE_PKG")))
(unless (find-package "SERVICE_PKG::NUMBER")
  (make-package "SERVICE_PKG::NUMBER"))
(unless (find-package "SERVICE_PKG::NUMBERREQUEST")
  (make-package "SERVICE_PKG::NUMBERREQUEST"))
(unless (find-package "SERVICE_PKG::NUMBERRESPONSE")
  (make-package "SERVICE_PKG::NUMBERRESPONSE"))

(in-package "ROS")





(defclass service_pkg::numberRequest
  :super ros::object
  :slots (_number ))

(defmethod service_pkg::numberRequest
  (:init
   (&key
    ((:number __number) 0.0)
    )
   (send-super :init)
   (setq _number (float __number))
   self)
  (:number
   (&optional __number)
   (if __number (setq _number __number)) _number)
  (:serialization-length
   ()
   (+
    ;; float32 _number
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _number
       (sys::poke _number (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _number
     (setq _number (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass service_pkg::numberResponse
  :super ros::object
  :slots (_feedback ))

(defmethod service_pkg::numberResponse
  (:init
   (&key
    ((:feedback __feedback) nil)
    )
   (send-super :init)
   (setq _feedback __feedback)
   self)
  (:feedback
   (&optional __feedback)
   (if __feedback (setq _feedback __feedback)) _feedback)
  (:serialization-length
   ()
   (+
    ;; bool _feedback
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _feedback
       (if _feedback (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _feedback
     (setq _feedback (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass service_pkg::number
  :super ros::object
  :slots ())

(setf (get service_pkg::number :md5sum-) "856707387f0b62b7754ee4f39be9c0f3")
(setf (get service_pkg::number :datatype-) "service_pkg/number")
(setf (get service_pkg::number :request) service_pkg::numberRequest)
(setf (get service_pkg::number :response) service_pkg::numberResponse)

(defmethod service_pkg::numberRequest
  (:response () (instance service_pkg::numberResponse :init)))

(setf (get service_pkg::numberRequest :md5sum-) "856707387f0b62b7754ee4f39be9c0f3")
(setf (get service_pkg::numberRequest :datatype-) "service_pkg/numberRequest")
(setf (get service_pkg::numberRequest :definition-)
      "float32 number
---
bool feedback

")

(setf (get service_pkg::numberResponse :md5sum-) "856707387f0b62b7754ee4f39be9c0f3")
(setf (get service_pkg::numberResponse :datatype-) "service_pkg/numberResponse")
(setf (get service_pkg::numberResponse :definition-)
      "float32 number
---
bool feedback

")



(provide :service_pkg/number "856707387f0b62b7754ee4f39be9c0f3")


