
(cl:in-package :asdf)

(defsystem "random_create-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "RandomNum" :depends-on ("_package_RandomNum"))
    (:file "_package_RandomNum" :depends-on ("_package"))
  ))