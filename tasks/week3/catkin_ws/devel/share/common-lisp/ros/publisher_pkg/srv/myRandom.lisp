; Auto-generated. Do not edit!


(cl:in-package publisher_pkg-srv)


;//! \htmlinclude myRandom-request.msg.html

(cl:defclass <myRandom-request> (roslisp-msg-protocol:ros-message)
  ((random_num
    :reader random_num
    :initarg :random_num
    :type cl:float
    :initform 0.0))
)

(cl:defclass myRandom-request (<myRandom-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <myRandom-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'myRandom-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name publisher_pkg-srv:<myRandom-request> is deprecated: use publisher_pkg-srv:myRandom-request instead.")))

(cl:ensure-generic-function 'random_num-val :lambda-list '(m))
(cl:defmethod random_num-val ((m <myRandom-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader publisher_pkg-srv:random_num-val is deprecated.  Use publisher_pkg-srv:random_num instead.")
  (random_num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <myRandom-request>) ostream)
  "Serializes a message object of type '<myRandom-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'random_num))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <myRandom-request>) istream)
  "Deserializes a message object of type '<myRandom-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'random_num) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<myRandom-request>)))
  "Returns string type for a service object of type '<myRandom-request>"
  "publisher_pkg/myRandomRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'myRandom-request)))
  "Returns string type for a service object of type 'myRandom-request"
  "publisher_pkg/myRandomRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<myRandom-request>)))
  "Returns md5sum for a message object of type '<myRandom-request>"
  "af3f1147d7daae631b82b1a427cd4a2f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'myRandom-request)))
  "Returns md5sum for a message object of type 'myRandom-request"
  "af3f1147d7daae631b82b1a427cd4a2f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<myRandom-request>)))
  "Returns full string definition for message of type '<myRandom-request>"
  (cl:format cl:nil "float32 random_num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'myRandom-request)))
  "Returns full string definition for message of type 'myRandom-request"
  (cl:format cl:nil "float32 random_num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <myRandom-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <myRandom-request>))
  "Converts a ROS message object to a list"
  (cl:list 'myRandom-request
    (cl:cons ':random_num (random_num msg))
))
;//! \htmlinclude myRandom-response.msg.html

(cl:defclass <myRandom-response> (roslisp-msg-protocol:ros-message)
  ((judge
    :reader judge
    :initarg :judge
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass myRandom-response (<myRandom-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <myRandom-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'myRandom-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name publisher_pkg-srv:<myRandom-response> is deprecated: use publisher_pkg-srv:myRandom-response instead.")))

(cl:ensure-generic-function 'judge-val :lambda-list '(m))
(cl:defmethod judge-val ((m <myRandom-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader publisher_pkg-srv:judge-val is deprecated.  Use publisher_pkg-srv:judge instead.")
  (judge m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <myRandom-response>) ostream)
  "Serializes a message object of type '<myRandom-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'judge) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <myRandom-response>) istream)
  "Deserializes a message object of type '<myRandom-response>"
    (cl:setf (cl:slot-value msg 'judge) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<myRandom-response>)))
  "Returns string type for a service object of type '<myRandom-response>"
  "publisher_pkg/myRandomResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'myRandom-response)))
  "Returns string type for a service object of type 'myRandom-response"
  "publisher_pkg/myRandomResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<myRandom-response>)))
  "Returns md5sum for a message object of type '<myRandom-response>"
  "af3f1147d7daae631b82b1a427cd4a2f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'myRandom-response)))
  "Returns md5sum for a message object of type 'myRandom-response"
  "af3f1147d7daae631b82b1a427cd4a2f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<myRandom-response>)))
  "Returns full string definition for message of type '<myRandom-response>"
  (cl:format cl:nil "bool judge~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'myRandom-response)))
  "Returns full string definition for message of type 'myRandom-response"
  (cl:format cl:nil "bool judge~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <myRandom-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <myRandom-response>))
  "Converts a ROS message object to a list"
  (cl:list 'myRandom-response
    (cl:cons ':judge (judge msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'myRandom)))
  'myRandom-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'myRandom)))
  'myRandom-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'myRandom)))
  "Returns string type for a service object of type '<myRandom>"
  "publisher_pkg/myRandom")