; Auto-generated. Do not edit!


(cl:in-package service_pkg-srv)


;//! \htmlinclude number-request.msg.html

(cl:defclass <number-request> (roslisp-msg-protocol:ros-message)
  ((number
    :reader number
    :initarg :number
    :type cl:float
    :initform 0.0))
)

(cl:defclass number-request (<number-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <number-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'number-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name service_pkg-srv:<number-request> is deprecated: use service_pkg-srv:number-request instead.")))

(cl:ensure-generic-function 'number-val :lambda-list '(m))
(cl:defmethod number-val ((m <number-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader service_pkg-srv:number-val is deprecated.  Use service_pkg-srv:number instead.")
  (number m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <number-request>) ostream)
  "Serializes a message object of type '<number-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'number))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <number-request>) istream)
  "Deserializes a message object of type '<number-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'number) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<number-request>)))
  "Returns string type for a service object of type '<number-request>"
  "service_pkg/numberRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'number-request)))
  "Returns string type for a service object of type 'number-request"
  "service_pkg/numberRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<number-request>)))
  "Returns md5sum for a message object of type '<number-request>"
  "856707387f0b62b7754ee4f39be9c0f3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'number-request)))
  "Returns md5sum for a message object of type 'number-request"
  "856707387f0b62b7754ee4f39be9c0f3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<number-request>)))
  "Returns full string definition for message of type '<number-request>"
  (cl:format cl:nil "float32 number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'number-request)))
  "Returns full string definition for message of type 'number-request"
  (cl:format cl:nil "float32 number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <number-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <number-request>))
  "Converts a ROS message object to a list"
  (cl:list 'number-request
    (cl:cons ':number (number msg))
))
;//! \htmlinclude number-response.msg.html

(cl:defclass <number-response> (roslisp-msg-protocol:ros-message)
  ((feedback
    :reader feedback
    :initarg :feedback
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass number-response (<number-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <number-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'number-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name service_pkg-srv:<number-response> is deprecated: use service_pkg-srv:number-response instead.")))

(cl:ensure-generic-function 'feedback-val :lambda-list '(m))
(cl:defmethod feedback-val ((m <number-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader service_pkg-srv:feedback-val is deprecated.  Use service_pkg-srv:feedback instead.")
  (feedback m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <number-response>) ostream)
  "Serializes a message object of type '<number-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'feedback) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <number-response>) istream)
  "Deserializes a message object of type '<number-response>"
    (cl:setf (cl:slot-value msg 'feedback) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<number-response>)))
  "Returns string type for a service object of type '<number-response>"
  "service_pkg/numberResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'number-response)))
  "Returns string type for a service object of type 'number-response"
  "service_pkg/numberResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<number-response>)))
  "Returns md5sum for a message object of type '<number-response>"
  "856707387f0b62b7754ee4f39be9c0f3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'number-response)))
  "Returns md5sum for a message object of type 'number-response"
  "856707387f0b62b7754ee4f39be9c0f3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<number-response>)))
  "Returns full string definition for message of type '<number-response>"
  (cl:format cl:nil "bool feedback~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'number-response)))
  "Returns full string definition for message of type 'number-response"
  (cl:format cl:nil "bool feedback~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <number-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <number-response>))
  "Converts a ROS message object to a list"
  (cl:list 'number-response
    (cl:cons ':feedback (feedback msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'number)))
  'number-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'number)))
  'number-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'number)))
  "Returns string type for a service object of type '<number>"
  "service_pkg/number")