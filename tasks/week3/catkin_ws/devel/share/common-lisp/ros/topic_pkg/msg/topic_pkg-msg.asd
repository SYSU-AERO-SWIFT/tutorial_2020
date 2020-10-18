
(cl:in-package :asdf)

(defsystem "topic_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "range" :depends-on ("_package_range"))
    (:file "_package_range" :depends-on ("_package"))
  ))