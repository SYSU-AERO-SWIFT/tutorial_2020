;; Auto-generated. Do not edit!


(when (boundp 'random_create::RandomNum)
  (if (not (find-package "RANDOM_CREATE"))
    (make-package "RANDOM_CREATE"))
  (shadow 'RandomNum (find-package "RANDOM_CREATE")))
(unless (find-package "RANDOM_CREATE::RANDOMNUM")
  (make-package "RANDOM_CREATE::RANDOMNUM"))

(in-package "ROS")
;;//! \htmlinclude RandomNum.msg.html


(defclass random_create::RandomNum
  :super ros::object
  :slots (_randNum _callback ))

(defmethod random_create::RandomNum
  (:init
   (&key
    ((:randNum __randNum) 0)
    ((:callback __callback) 0)
    )
   (send-super :init)
   (setq _randNum (round __randNum))
   (setq _callback (round __callback))
   self)
  (:randNum
   (&optional __randNum)
   (if __randNum (setq _randNum __randNum)) _randNum)
  (:callback
   (&optional __callback)
   (if __callback (setq _callback __callback)) _callback)
  (:serialization-length
   ()
   (+
    ;; uint8 _randNum
    1
    ;; uint8 _callback
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _randNum
       (write-byte _randNum s)
     ;; uint8 _callback
       (write-byte _callback s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _randNum
     (setq _randNum (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _callback
     (setq _callback (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get random_create::RandomNum :md5sum-) "8a632e4b30aa8c63125730332e5ca6e8")
(setf (get random_create::RandomNum :datatype-) "random_create/RandomNum")
(setf (get random_create::RandomNum :definition-)
      "uint8 randNum
uint8 callback

")



(provide :random_create/RandomNum "8a632e4b30aa8c63125730332e5ca6e8")


