; Auto-generated. Do not edit!


(cl:in-package random_create-msg)


;//! \htmlinclude RandomNum.msg.html

(cl:defclass <RandomNum> (roslisp-msg-protocol:ros-message)
  ((randNum
    :reader randNum
    :initarg :randNum
    :type cl:fixnum
    :initform 0)
   (callback
    :reader callback
    :initarg :callback
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RandomNum (<RandomNum>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RandomNum>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RandomNum)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name random_create-msg:<RandomNum> is deprecated: use random_create-msg:RandomNum instead.")))

(cl:ensure-generic-function 'randNum-val :lambda-list '(m))
(cl:defmethod randNum-val ((m <RandomNum>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader random_create-msg:randNum-val is deprecated.  Use random_create-msg:randNum instead.")
  (randNum m))

(cl:ensure-generic-function 'callback-val :lambda-list '(m))
(cl:defmethod callback-val ((m <RandomNum>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader random_create-msg:callback-val is deprecated.  Use random_create-msg:callback instead.")
  (callback m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RandomNum>) ostream)
  "Serializes a message object of type '<RandomNum>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'randNum)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'callback)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RandomNum>) istream)
  "Deserializes a message object of type '<RandomNum>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'randNum)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'callback)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RandomNum>)))
  "Returns string type for a message object of type '<RandomNum>"
  "random_create/RandomNum")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RandomNum)))
  "Returns string type for a message object of type 'RandomNum"
  "random_create/RandomNum")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RandomNum>)))
  "Returns md5sum for a message object of type '<RandomNum>"
  "8a632e4b30aa8c63125730332e5ca6e8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RandomNum)))
  "Returns md5sum for a message object of type 'RandomNum"
  "8a632e4b30aa8c63125730332e5ca6e8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RandomNum>)))
  "Returns full string definition for message of type '<RandomNum>"
  (cl:format cl:nil "uint8 randNum~%uint8 callback~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RandomNum)))
  "Returns full string definition for message of type 'RandomNum"
  (cl:format cl:nil "uint8 randNum~%uint8 callback~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RandomNum>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RandomNum>))
  "Converts a ROS message object to a list"
  (cl:list 'RandomNum
    (cl:cons ':randNum (randNum msg))
    (cl:cons ':callback (callback msg))
))
