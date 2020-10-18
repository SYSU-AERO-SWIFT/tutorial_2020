; Auto-generated. Do not edit!


(cl:in-package topic_pkg-msg)


;//! \htmlinclude range.msg.html

(cl:defclass <range> (roslisp-msg-protocol:ros-message)
  ((number
    :reader number
    :initarg :number
    :type cl:fixnum
    :initform 0))
)

(cl:defclass range (<range>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <range>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'range)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name topic_pkg-msg:<range> is deprecated: use topic_pkg-msg:range instead.")))

(cl:ensure-generic-function 'number-val :lambda-list '(m))
(cl:defmethod number-val ((m <range>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader topic_pkg-msg:number-val is deprecated.  Use topic_pkg-msg:number instead.")
  (number m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <range>) ostream)
  "Serializes a message object of type '<range>"
  (cl:let* ((signed (cl:slot-value msg 'number)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <range>) istream)
  "Deserializes a message object of type '<range>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'number) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<range>)))
  "Returns string type for a message object of type '<range>"
  "topic_pkg/range")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'range)))
  "Returns string type for a message object of type 'range"
  "topic_pkg/range")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<range>)))
  "Returns md5sum for a message object of type '<range>"
  "6500e1e658110ec1daa9475082592be3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'range)))
  "Returns md5sum for a message object of type 'range"
  "6500e1e658110ec1daa9475082592be3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<range>)))
  "Returns full string definition for message of type '<range>"
  (cl:format cl:nil "int16 number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'range)))
  "Returns full string definition for message of type 'range"
  (cl:format cl:nil "int16 number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <range>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <range>))
  "Converts a ROS message object to a list"
  (cl:list 'range
    (cl:cons ':number (number msg))
))
