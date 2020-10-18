
(cl:in-package :asdf)

(defsystem "publisher_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "theRandomNum" :depends-on ("_package_theRandomNum"))
    (:file "_package_theRandomNum" :depends-on ("_package"))
  ))