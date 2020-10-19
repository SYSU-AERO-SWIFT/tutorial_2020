
(cl:in-package :asdf)

(defsystem "publisher_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "myRandom" :depends-on ("_package_myRandom"))
    (:file "_package_myRandom" :depends-on ("_package"))
  ))