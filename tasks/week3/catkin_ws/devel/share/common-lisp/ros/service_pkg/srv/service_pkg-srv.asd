
(cl:in-package :asdf)

(defsystem "service_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "number" :depends-on ("_package_number"))
    (:file "_package_number" :depends-on ("_package"))
  ))