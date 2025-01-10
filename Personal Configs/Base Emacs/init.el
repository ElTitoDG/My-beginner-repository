;; Melpa install
(require 'package)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/") t)
;; Comment/uncomment this line to enable MELPA Stable if desired.  See `package-archive-priorities`
;; and `package-pinned-packages`. Most users will not need or want to do this.
;;(add-to-list 'package-archives '("melpa-stable" . "https://stable.melpa.org/packages/") t)
(package-initialize)
;; End Melpa install


;; GNU Devel packages
(add-to-list 'package-archives '("gnu-devel" . "https://elpa.gnu.org/devel/"))

;; Dashboard start-up
(require 'dashboard)
(dashboard-setup-startup-hook)

;; Projectile set-up
(projectile-mode +1)
;; Recommended keymap prefix on macOS
(define-key projectile-mode-map (kbd "s-p") 'projectile-command-map)

;; Move custom variables to separate file and load it
(setq custom-file (locate-user-emacs-file "custom-vars.el"))
(load custom-file 'noerror 'nomessage)
