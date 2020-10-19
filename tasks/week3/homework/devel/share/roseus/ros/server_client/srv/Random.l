;; Auto-generated. Do not edit!


(when (boundp 'server_client::Random)
  (if (not (find-package "SERVER_CLIENT"))
    (make-package "SERVER_CLIENT"))
  (shadow 'Random (find-package "SERVER_CLIENT")))
(unless (find-package "SERVER_CLIENT::RANDOM")
  (make-package "SERVER_CLIENT::RANDOM"))
(unless (find-package "SERVER_CLIENT::RANDOMREQUEST")
  (make-package "SERVER_CLIENT::RANDOMREQUEST"))
(unless (find-package "SERVER_CLIENT::RANDOMRESPONSE")
  (make-package "SERVER_CLIENT::RANDOMRESPONSE"))

(in-package "ROS")





(defclass server_client::RandomRequest
  :super ros::object
  :slots (_number ))

(defmethod server_client::RandomRequest
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

(defclass server_client::RandomResponse
  :super ros::object
  :slots (_result _answer ))

(defmethod server_client::RandomResponse
  (:init
   (&key
    ((:result __result) "")
    ((:answer __answer) nil)
    )
   (send-super :init)
   (setq _result (string __result))
   (setq _answer __answer)
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:answer
   (&optional __answer)
   (if __answer (setq _answer __answer)) _answer)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ;; bool _answer
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;; bool _answer
       (if _answer (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _answer
     (setq _answer (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass server_client::Random
  :super ros::object
  :slots ())

(setf (get server_client::Random :md5sum-) "9ce749d1ee926b7f0c91f1f5eca73de3")
(setf (get server_client::Random :datatype-) "server_client/Random")
(setf (get server_client::Random :request) server_client::RandomRequest)
(setf (get server_client::Random :response) server_client::RandomResponse)

(defmethod server_client::RandomRequest
  (:response () (instance server_client::RandomResponse :init)))

(setf (get server_client::RandomRequest :md5sum-) "9ce749d1ee926b7f0c91f1f5eca73de3")
(setf (get server_client::RandomRequest :datatype-) "server_client/RandomRequest")
(setf (get server_client::RandomRequest :definition-)
      "float32 number
---
string result
bool answer

")

(setf (get server_client::RandomResponse :md5sum-) "9ce749d1ee926b7f0c91f1f5eca73de3")
(setf (get server_client::RandomResponse :datatype-) "server_client/RandomResponse")
(setf (get server_client::RandomResponse :definition-)
      "float32 number
---
string result
bool answer

")



(provide :server_client/Random "9ce749d1ee926b7f0c91f1f5eca73de3")


