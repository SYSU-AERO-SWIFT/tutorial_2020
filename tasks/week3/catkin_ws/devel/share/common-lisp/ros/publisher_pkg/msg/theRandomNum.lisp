; Auto-generated. Do not edit!


(cl:in-package publisher_pkg-msg)


;//! \htmlinclude theRandomNum.msg.html

(cl:defclass <theRandomNum> (roslisp-msg-protocol:ros-message)
  ((data
    :reader data
    :initarg :data
    :type cl:float
    :initform 0.0))
)

(cl:defclass theRandomNum (<theRandomNum>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <theRandomNum>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'theRandomNum)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name publisher_pkg-msg:<theRandomNum> is deprecated: use publisher_pkg-msg:theRandomNum instead.")))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <theRandomNum>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader publisher_pkg-msg:data-val is deprecated.  Use publisher_pkg-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <theRandomNum>) ostream)
  "Serializes a message object of type '<theRandomNum>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <theRandomNum>) istream)
  "Deserializes a message object of type '<theRandomNum>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'data) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<theRandomNum>)))
  "Returns string type for a message object of type '<theRandomNum>"
  "publisher_pkg/theRandomNum")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'theRandomNum)))
  "Returns string type for a message object of type 'theRandomNum"
  "publisher_pkg/theRandomNum")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<theRandomNum>)))
  "Returns md5sum for a message object of type '<theRandomNum>"
  "73fcbf46b49191e672908e50842a83d4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'theRandomNum)))
  "Returns md5sum for a message object of type 'theRandomNum"
  "73fcbf46b49191e672908e50842a83d4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<theRandomNum>)))
  "Returns full string definition for message of type '<theRandomNum>"
  (cl:format cl:nil "float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'theRandomNum)))
  "Returns full string definition for message of type 'theRandomNum"
  (cl:format cl:nil "float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <theRandomNum>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <theRandomNum>))
  "Converts a ROS message object to a list"
  (cl:list 'theRandomNum
    (cl:cons ':data (data msg))
))
