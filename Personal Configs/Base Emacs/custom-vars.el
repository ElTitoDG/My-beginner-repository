;;; -*- lexical-binding: t -*-
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-enabled-themes '(gruber-darker))
 '(custom-safe-themes
   '("e13beeb34b932f309fb2c360a04a460821ca99fe58f69e65557d6c1b10ba18c7"
     default))
 '(package-selected-packages
   '(ace-window all-the-icons company dap-mode dashboard flycheck
		gruber-darker-theme helm-lsp lsp-ivy lsp-jedi lsp-mode
		lsp-treemacs lsp-ui magit projectile treemacs
		which-key)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

;; Basic config
(setq backup-inhibited t)
(setq inhibit-startup-message t)
(setq-default cursor-type 'bar)
(menu-bar-mode -1)
(tool-bar-mode -1)
(electric-pair-mode 1)
(global-display-line-numbers-mode 1)

;; Font config
(add-to-list 'default-frame-alist
	     '(font . "Iosevka Nerd Font-16"))

;; Frame Config
(setq initial-frame-alist
      (append initial-frame-alist
              '((width  . 234)
                (height . 52))))

;; User defined keybinds
(keymap-global-set "C-x t t" 'treemacs)

;; Dashboard set-up
;; Set the title
(setq dashboard-banner-logo-title "Welcome to Emacs Dashboard")
;; Set the banner
(setq dashboard-startup-banner 'official)
;; Content is not centered by default. To center, set
(setq dashboard-center-content t)
;; vertically center content
(setq dashboard-vertically-center-content t)

(setq dashboard-items '((recents   . 5)
                        (bookmarks . 5)
                        (projects  . 5)
                        (agenda    . 5)
                        (registers . 5)))
