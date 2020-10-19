; Auto-generated. Do not edit!


(cl:in-package direction_publisher-msg)


;//! \htmlinclude direction_msg.msg.html

(cl:defclass <direction_msg> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:fixnum
    :initform 0)
   (rusult
    :reader rusult
    :initarg :rusult
    :type cl:fixnum
    :initform 0))
)

(cl:defclass direction_msg (<direction_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <direction_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'direction_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name direction_publisher-msg:<direction_msg> is deprecated: use direction_publisher-msg:direction_msg instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <direction_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader direction_publisher-msg:state-val is deprecated.  Use direction_publisher-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'rusult-val :lambda-list '(m))
(cl:defmethod rusult-val ((m <direction_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader direction_publisher-msg:rusult-val is deprecated.  Use direction_publisher-msg:rusult instead.")
  (rusult m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <direction_msg>) ostream)
  "Serializes a message object of type '<direction_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rusult)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <direction_msg>) istream)
  "Deserializes a message object of type '<direction_msg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rusult)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<direction_msg>)))
  "Returns string type for a message object of type '<direction_msg>"
  "direction_publisher/direction_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'direction_msg)))
  "Returns string type for a message object of type 'direction_msg"
  "direction_publisher/direction_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<direction_msg>)))
  "Returns md5sum for a message object of type '<direction_msg>"
  "b5be09278843569de4bf740957660e27")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'direction_msg)))
  "Returns md5sum for a message object of type 'direction_msg"
  "b5be09278843569de4bf740957660e27")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<direction_msg>)))
  "Returns full string definition for message of type '<direction_msg>"
  (cl:format cl:nil "uint8 state~%uint8 rusult~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'direction_msg)))
  "Returns full string definition for message of type 'direction_msg"
  (cl:format cl:nil "uint8 state~%uint8 rusult~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <direction_msg>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <direction_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'direction_msg
    (cl:cons ':state (state msg))
    (cl:cons ':rusult (rusult msg))
))
