
(cl:in-package :asdf)

(defsystem "direction_publisher-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "direction_msg" :depends-on ("_package_direction_msg"))
    (:file "_package_direction_msg" :depends-on ("_package"))
  ))