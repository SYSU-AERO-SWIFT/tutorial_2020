;; Auto-generated. Do not edit!


(when (boundp 'direction_publisher::direction_msg)
  (if (not (find-package "DIRECTION_PUBLISHER"))
    (make-package "DIRECTION_PUBLISHER"))
  (shadow 'direction_msg (find-package "DIRECTION_PUBLISHER")))
(unless (find-package "DIRECTION_PUBLISHER::DIRECTION_MSG")
  (make-package "DIRECTION_PUBLISHER::DIRECTION_MSG"))

(in-package "ROS")
;;//! \htmlinclude direction_msg.msg.html


(defclass direction_publisher::direction_msg
  :super ros::object
  :slots (_state _rusult ))

(defmethod direction_publisher::direction_msg
  (:init
   (&key
    ((:state __state) 0)
    ((:rusult __rusult) 0)
    )
   (send-super :init)
   (setq _state (round __state))
   (setq _rusult (round __rusult))
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:rusult
   (&optional __rusult)
   (if __rusult (setq _rusult __rusult)) _rusult)
  (:serialization-length
   ()
   (+
    ;; uint8 _state
    1
    ;; uint8 _rusult
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _state
       (write-byte _state s)
     ;; uint8 _rusult
       (write-byte _rusult s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _state
     (setq _state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _rusult
     (setq _rusult (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get direction_publisher::direction_msg :md5sum-) "b5be09278843569de4bf740957660e27")
(setf (get direction_publisher::direction_msg :datatype-) "direction_publisher/direction_msg")
(setf (get direction_publisher::direction_msg :definition-)
      "uint8 state
uint8 rusult

")



(provide :direction_publisher/direction_msg "b5be09278843569de4bf740957660e27")


