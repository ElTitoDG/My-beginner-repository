;; Melpa Install
(require 'package)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/") t)
;; Comment/uncomment this line to enable MELPA Stable if desired.  See `package-archive-priorities`
;; and `package-pinned-packages`. Most users will not need or want to do this.
;;(add-to-list 'package-archives '("melpa-stable" . "https://stable.melpa.org/packages/") t)
(package-initialize)

(setq custom-file "~/.emacs.custom.el")

(add-to-list 'default-frame-alist
	     '(font . "Iosevka Nerd Font-16"))

(add-to-list 'load-path (expand-file-name "~/.emacs.d/xcode-theme"))
(require 'xcode-dark-theme)

;; Simple C Mode Config
;; Load path of Simple C Mode
(add-to-list 'load-path (expand-file-name "~/.emacs.d/simpc-mode/"))
(require 'simpc-mode)

;; Define a toggle function for switching modes
(defun toggle-c-lsp-simpc-modes ()
  "Toggle between c-mode, simpc-mode, and lsp-mode."
  (interactive)
  (cond
   ;; If in lsp-mode, switch to c-mode first
   ((and (bound-and-true-p lsp-mode) (derived-mode-p 'c-mode))
    (c-mode)
    (message "Switched to c-mode from lsp-mode"))
   ;; If in simpc-mode, switch to c-mode
   ((derived-mode-p 'simpc-mode)
    (c-mode)
    (message "Switched to c-mode from simpc-mode"))
   ;; If in c-mode, switch to simpc-mode
   ((derived-mode-p 'c-mode)
    (simpc-mode)
    (message "Switched to simpc-mode"))
   ;; If in any other mode, switch to c-mode
   (t
    (c-mode)
    (message "Switched to c-mode"))))

;; Bind the toggle function to a key sequence
(global-set-key (kbd "C-c t") 'toggle-c-lsp-simpc-modes)

;; Load Dashboard
(require 'dashboard)
(dashboard-setup-startup-hook)

;; Frame Config
(setq initial-frame-alist
      (append initial-frame-alist
              '((width  . 234)
                (height . 52))))

(setq-default cursor-type 'bar)
(menu-bar-mode 0)
(tool-bar-mode 0)
(electric-pair-mode 1)
(global-display-line-numbers-mode)



(load-file custom-file)
