; Auto-generated. Do not edit!


(cl:in-package server_client-srv)


;//! \htmlinclude Random-request.msg.html

(cl:defclass <Random-request> (roslisp-msg-protocol:ros-message)
  ((number
    :reader number
    :initarg :number
    :type cl:float
    :initform 0.0))
)

(cl:defclass Random-request (<Random-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Random-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Random-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name server_client-srv:<Random-request> is deprecated: use server_client-srv:Random-request instead.")))

(cl:ensure-generic-function 'number-val :lambda-list '(m))
(cl:defmethod number-val ((m <Random-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader server_client-srv:number-val is deprecated.  Use server_client-srv:number instead.")
  (number m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Random-request>) ostream)
  "Serializes a message object of type '<Random-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'number))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Random-request>) istream)
  "Deserializes a message object of type '<Random-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'number) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Random-request>)))
  "Returns string type for a service object of type '<Random-request>"
  "server_client/RandomRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Random-request)))
  "Returns string type for a service object of type 'Random-request"
  "server_client/RandomRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Random-request>)))
  "Returns md5sum for a message object of type '<Random-request>"
  "9ce749d1ee926b7f0c91f1f5eca73de3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Random-request)))
  "Returns md5sum for a message object of type 'Random-request"
  "9ce749d1ee926b7f0c91f1f5eca73de3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Random-request>)))
  "Returns full string definition for message of type '<Random-request>"
  (cl:format cl:nil "float32 number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Random-request)))
  "Returns full string definition for message of type 'Random-request"
  (cl:format cl:nil "float32 number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Random-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Random-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Random-request
    (cl:cons ':number (number msg))
))
;//! \htmlinclude Random-response.msg.html

(cl:defclass <Random-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:string
    :initform "")
   (answer
    :reader answer
    :initarg :answer
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Random-response (<Random-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Random-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Random-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name server_client-srv:<Random-response> is deprecated: use server_client-srv:Random-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <Random-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader server_client-srv:result-val is deprecated.  Use server_client-srv:result instead.")
  (result m))

(cl:ensure-generic-function 'answer-val :lambda-list '(m))
(cl:defmethod answer-val ((m <Random-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader server_client-srv:answer-val is deprecated.  Use server_client-srv:answer instead.")
  (answer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Random-response>) ostream)
  "Serializes a message object of type '<Random-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'result))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'answer) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Random-response>) istream)
  "Deserializes a message object of type '<Random-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'result) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'answer) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Random-response>)))
  "Returns string type for a service object of type '<Random-response>"
  "server_client/RandomResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Random-response)))
  "Returns string type for a service object of type 'Random-response"
  "server_client/RandomResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Random-response>)))
  "Returns md5sum for a message object of type '<Random-response>"
  "9ce749d1ee926b7f0c91f1f5eca73de3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Random-response)))
  "Returns md5sum for a message object of type 'Random-response"
  "9ce749d1ee926b7f0c91f1f5eca73de3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Random-response>)))
  "Returns full string definition for message of type '<Random-response>"
  (cl:format cl:nil "string result~%bool answer~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Random-response)))
  "Returns full string definition for message of type 'Random-response"
  (cl:format cl:nil "string result~%bool answer~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Random-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'result))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Random-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Random-response
    (cl:cons ':result (result msg))
    (cl:cons ':answer (answer msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Random)))
  'Random-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Random)))
  'Random-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Random)))
  "Returns string type for a service object of type '<Random>"
  "server_client/Random")