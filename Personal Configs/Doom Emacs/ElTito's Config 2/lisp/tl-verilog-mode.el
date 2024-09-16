;;; tl-verilog-mode.el --- major mode for editing verilog source in Emacs

;; Copyright (C) 2015 Free Software Foundation, Inc.

;; Author of tl-verilog-mode.el:
;;    Steve Hoover <steve.hoover@rweda.com>
;;    http://www.redwoodeda.com
;; Created: June 2015


;; This file is for use with GNU Emacs and is distributed under
;; the same GNU General Public License used by GNU Emacs.

;; GNU Emacs is free software: you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation, either version 3 of the License, or
;; (at your option) any later version.

;; GNU Emacs is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.

;;; Commentary:

;; USAGE
;; =====

;; A major mode for editing TL-Verilog source code, implemented as an
;; extension of Verilog mode.
;;
;; Verilog mode is described as follows:
;; A major mode for editing Verilog and SystemVerilog HDL source code (IEEE
;; 1364-2005 and IEEE 1800-2012 standards).  When you have entered Verilog
;; mode, you may get more info by pressing C-h m. You may also get online
;; help describing various functions by: C-h f <Name of function you want
;; described>


;; KNOWN BUGS / BUG REPORTS
;; =======================

;; TL-Verilog and SystemVerilog are rapidly evolving language, and hence
;; these modes are under continuous development.  Please triage issues
;; before submitting.  If you can reproduce your issue in verilog-mode
;; report issues, as recommended for that mode, to the issue tracker at
;;
;;    http://www.veripool.org/verilog-mode
;;
;; Please use tl-verilog-submit-bug-report to submit a report; type C-c
;; C-b to invoke this and as a result we will have a much easier time
;; of reproducing the bug you find, and hence fixing it.
;;
;; For bugs that are specific to TL-Verilog mode, please use
;; tl-verilog-submit-bug-report to submit a report.


;; INSTALLING THE MODE
;; ===================

;; The short list of installation instructions are: To set up
;; automatic TL-Verilog mode, put this file in your load path, and put
;; the following in code (please un-comment it first!) in your
;; ~/.emacs, or in your site's site-load.el

; (autoload 'tl-verilog-mode "tl-verilog-mode" "TL-Verilog mode" t )
; (add-to-list 'auto-mode-alist '("\\.tlv\\'" . tl-verilog-mode))
; (add-hook 'tl-verilog-mode-hook '(lambda () (font-lock-mode 1)))

;; Here's an example of some more-complete .emacs content:
;
; Useful functions for manipulating load-path:
; (defun prepend-path ( my-path )
; (setq load-path (cons (expand-file-name my-path) load-path)))
; (defun append-path ( my-path )
;  (setq load-path (append load-path (list (expand-file-name my-path)))))
; ;; Look first in the directory ~/elisp for elisp files
; (prepend-path "~/elisp")
; ;; Load tl-verilog mode only when needed
; (autoload 'tl-verilog-mode "tl-verilog-mode" "TL-Verilog mode" t )
; ;; Any files that end in .tlv should be in verilog mode
; (add-to-list 'auto-mode-alist '("\\.tlv\\'" . tl-verilog-mode))
; ;; Any files in tl-verilog mode should have their keywords colorized
; (add-hook 'tl-verilog-mode-hook '(lambda () (font-lock-mode 1)))


;; Be sure to examine the help for verilog-auto, and the other
;; verilog-auto-* functions for some major coding time savers.
;;
;; If you want to customize Verilog mode to fit your needs better,
;; you may add the below lines (the values of the variables presented
;; here are the defaults). Note also that if you use an Emacs that
;; supports custom, it's probably better to use the custom menu to
;; edit these.  If working as a member of a large team these settings
;; should be common across all users (in a site-start file), or set
;; in Local Variables in every file.  Otherwise, different people's
;; AUTO expansion may result in different whitespace changes.
;;
; ;; Enable syntax highlighting of **all** languages
; (global-font-lock-mode t)
;
; ;; User customization for Verilog mode
; (setq verilog-indent-level             3
;       verilog-indent-level-module      3
;       verilog-indent-level-declaration 3
;       verilog-indent-level-behavioral  3
;       verilog-indent-level-directive   1
;       verilog-case-indent              2
;       verilog-auto-newline             nil
;       verilog-auto-indent-on-newline   nil
;       verilog-tab-always-indent        nil
;       verilog-auto-endcomments         t
;       verilog-minimum-comment-distance 40
;       verilog-indent-begin-after-if    t
;       verilog-auto-lineup              'declarations
;       verilog-highlight-p1800-keywords nil
;       verilog-linter			 "my_lint_shell_command"
;       )

;; 

;;; History:
;;
;; See commit history at http://www.veripool.org/verilog-mode.html
;; (This section is required to appease checkdoc.)



;;; Code:

;; Required Verilog-mode version:
(defconst tl-verilog-mode-verilog-mode-version "2015-05-07-9797a27-vpo"
  "Version of the Verilog mode this TL-Verilog mode is based upon.")

;; This variable will always hold the version number of the mode.
;; The beginning of the string corresponds to the verilog-mode version
;; upon which this mode was based, with a TL-Verilog-Mode-specific
;; version string following "-tlv".
(defconst tl-verilog-mode-version
          (concat tl-verilog-mode-verilog-mode-version "-tlv-1.1-2015-05")
          "Version of this TL-Verilog mode.")
(defconst tl-verilog-mode-release-emacs nil
  "If non-nil, this version of TL-Verilog mode was released with Emacs itself.")

(defun tl-verilog-version ()
  "Inform caller of the version of this file."
  (interactive)
  (message "Using tl-verilog-mode version %s" tl-verilog-mode-version))

;; TL-Verilog-mode extends 'verilog-mode.
(condition-case nil
  (require 'verilog-mode)
  (error nil))
;; Check that the verilog-mode version is as needed.
(if (string= verilog-mode-version tl-verilog-mode-verilog-mode-version)
  t
  (message "Warning: tl-verilog-mode depends upon verilog-mode version %s but verilog-mode version is %s" tl-verilog-mode-verilog-mode-version verilog-mode-version))

(when (featurep 'xemacs)
  (message "Warning: TL-Verilog Mode has not been tested in XEmacs"))



(defun tl-verilog-customize ()
  "Customize variables and other settings used by Tl-Verilog-Mode."
  (interactive)
  (customize-group 'tl-verilog-mode))

(defun tl-verilog-font-customize ()
  "Customize fonts used by Tl-Verilog-Mode."
  (interactive)
  (if (fboundp 'customize-apropos)
      (customize-apropos "font-lock-*" 'faces)))

(defgroup tl-verilog-mode nil
  "Major mode for TL-Verilog source code."
  :version tl-verilog-mode-version
  :group 'languages)

; (defgroup tl-verilog-mode-fonts nil
;   "Facilitates easy customization fonts used in TL-Verilog source text"
;   :link '(customize-apropos "font-lock-*" 'faces)
;  :group 'tl-verilog-mode)

(defgroup tl-verilog-mode-indent nil
  "Customize indentation and highlighting of TL-Verilog source text."
  :group 'tl-verilog-mode)

;; SandPiper(TM) tool
(defcustom sandpiper
  "sandpiper"
  "Program and arguments to run SandPiper(TM).  This is invoked
with `run-sandpiper', and depending on the
`verilog-set-compile-command', may also be invoked when you type
\\[compile].  When the compile completes \\[next-error] will
take you to the next lint error."
  :type 'string
  :group 'tl-verilog-mode-actions)

(defcustom tl-verilog-preprocessor
  ;; Very few tools give preprocessed output, so we'll default to Verilog-Perl
  "vppreproc __FLAGS__ __FILE__"
  "Program and arguments to use to preprocess Verilog source.
This is invoked with `verilog-preprocess', and depending on the
`verilog-set-compile-command', may also be invoked when you type
\\[compile].  When the compile completes, \\[next-error] will
take you to the next lint error."
  :type 'string
  :group 'tl-verilog-mode-actions)
;; We don't mark it safe, as it's used as a shell command

(defvar tl-verilog-preprocess-history nil
  "History for `tl-verilog-preprocess'.")




;; TL-Verilog Font Definitions

;; Region
(defvar tlv-font-lock-region-face
  'tlv-font-lock-region-face
  "Font to use for TL-Verilog code region identifier.")
(defface tlv-font-lock-region-face
  '((t (:foreground "maroon" :overline "maroon" :weight bold)))
  "Font lock mode face used for TL-Verilog region identifiers."
  :group 'font-lock-highlighting-faces)

;; Local Region
(defvar tlv-font-lock-local-region-face
  'tlv-font-lock-local-region-face
  "Font to use for TL-Verilog local code region identifier.")
(defface tlv-font-lock-local-region-face
  '((t (:foreground "maroon" :weight bold)))
  "Font lock mode face used for TL-Verilog local region identifiers."
  :group 'font-lock-highlighting-faces)

;; Behavioral Hierarchy
(defvar tlv-font-lock-beh-hier-face
  'tlv-font-lock-beh-hier-face
  "Font to use for TL-Verilog behavioral hierarchy.")
(defface tlv-font-lock-beh-hier-face
  '((t (:foreground "#1090c0")))
  "Font lock mode face used for TL-Verilog behavioral hierarchy."
  :group 'font-lock-highlighting-faces)

;; Pipeline
(defvar
  tlv-font-lock-pipeline-face
  'tlv-font-lock-pipeline-face
  "Font to use for TLV pipeline identifiers")
(defface tlv-font-lock-pipeline-face
  '((t (:foreground "orange")))
  "Font lock mode face used for TLV pipeline identifiers."
  :group 'font-lock-highlighting-faces)

;; When
(defvar
  tlv-font-lock-when-face
  'tlv-font-lock-when-face
  "Font to use for TLV when identifiers")
(defface tlv-font-lock-when-face
  '((t (:foreground "#E04010")))
  "Font lock mode face used for TLV when identifiers."
  :group 'font-lock-highlighting-faces)

;; Stage
(defvar
  tlv-font-lock-stage-face
  'tlv-font-lock-stage-face
  "Font to use for TLV stage identifiers")
(defface tlv-font-lock-stage-face
  '((t (:foreground "#509050" :italic t)))
  "Font lock mode face used for TLV stage identifiers."
  :group 'font-lock-highlighting-faces)

;; Alignment
(defvar
  tlv-font-lock-alignment-face
  'tlv-font-lock-alignment-face
  "Font to use for TLV alignment identifiers")
(defface tlv-font-lock-alignment-face
  '((t (:foreground "#00D000")))
  "Font lock mode face used for TLV alignment identifiers."
  :group 'font-lock-highlighting-faces)

;; Constant
(defvar
  tlv-font-lock-constant-face
  'tlv-font-lock-constant-face
  "Font to use for TLV constant identifiers")
(defface tlv-font-lock-constant-face
  '((t (:foreground "medium blue")))
  "Font lock mode face used for TLV constant identifiers."
  :group 'font-lock-highlighting-faces)

;; Pipesignal
(defvar
  tlv-font-lock-pipesignal-face
  'tlv-font-lock-pipesignal-face
  "Font to use for TLV pipesignal identifiers")
(defface tlv-font-lock-pipesignal-face
  '((t (:foreground "purple")))
  "Font lock mode face used for TLV pipesignal identifiers."
  :group 'font-lock-highlighting-faces)

;; SV signal
(defvar
  tlv-font-lock-sv-signal-face
  'tlv-font-lock-sv-signal-face
  "Font to use for TLV SV signal identifiers")
(defface tlv-font-lock-sv-signal-face
  '((t (:foreground "gray45")))
  "Font lock mode face used for TLV SV signal identifiers."
  :group 'font-lock-highlighting-faces)

;; Attribute
(defvar
  tlv-font-lock-attribute-face
  'tlv-font-lock-attribute-face
  "Font to use for TLV attribute identifiers")
(defface tlv-font-lock-attribute-face
  '((t (:foreground "#503890" :italic t)))
  "Font lock mode face used for TLV attribute identifiers."
  :group 'font-lock-highlighting-faces)

;; M4 macros
(defvar tlv-font-lock-m4-macro-face
  'tlv-font-lock-m4-macro-face
  "Font to use for M4 macro instances (with m4_ prefix).")
(defface tlv-font-lock-m4-macro-face
  '((t (:foreground "medium blue" :underline "AntiqueWhite3" :weight bold)))
  "Font lock mode face used for M4 macro instances (with m4_ prefix)."
  :group 'font-lock-highlighting-faces)

;; M4+ macros (multi-line expansion)
(defvar tlv-font-lock-m4-plus-macro-face
  'tlv-font-lock-m4-plus-macro-face
  "Font to use for multi-line M4 macro instances (with m4+ prefix).")
(defface tlv-font-lock-m4-plus-macro-face
  '((t (:background "AntiqueWhite2" :foreground "medium blue" :overline "AntiqueWhite3" :underline "AntiqueWhite3" :weight bold)))
  "Font lock mode face used for multi-line M4 macro instances (with m4+ prefix)."
  :group 'font-lock-highlighting-faces)

;; Indentation
(defvar
  tlv-font-lock-indentation-face
  'tlv-font-lock-indentation-face
  "Font to use for indentation")
(defface tlv-font-lock-indentation-face
  '((t (:background "gray95" :foreground "red" :bold t)))
  "Font lock mode face used for indentation."
  :group 'font-lock-highlighting-faces)


;; Faces used in message string path for error cases.

;; Bad indentation
(defvar
  tlv-font-lock-bad-indentation-face
  'tlv-font-lock-bad-indentation-face
  "Font to use for bad indentation")
(defface tlv-font-lock-bad-indentation-face
  '((t (:background "red" :bold t)))
  "Font lock mode face used for bad indentation."
  :group 'font-lock-highlighting-faces)

;; Bad scope identifier
(defvar
  tlv-font-lock-bad-scope-face
  'tlv-font-lock-bad-scope-face
  "Font to use to indicate bad scope")
(defface tlv-font-lock-bad-scope-face
  '((t (:foreground "red" :bold t)))
  "Font lock mode face used for bad scope."
  :group 'font-lock-highlighting-faces)




;; SandPiper output message regexp.
(defvar tlv-error-regexp-emacs-alist
  '(
    (sandpiper
     "[A-Z_]*\\(\\(ERROR\\|BUG\\)\\|\\(WARNING\\)\\|\\(INFORM\\)\\)([0-9]+) ([^)]+): File '\\(.+\\)' Line \\([0-9]+\\) ?\\((char \\([0-9]+\\))\\)?" 5 6 8 (3 . 4))
   )
  "List of regexps for tools run in TL-Verilog mode.
See `compilation-error-regexp-alist' for the formatting.  For Emacs 22+.")


(defvar tlv-error-regexp-xemacs-alist
  ;; Emacs form is '((v-tool "re" 1 2) ...)
  ;; XEmacs form is '(verilog ("re" 1 2) ...)
  ;; So we can just map from Emacs to XEmacs
  (cons 'tl-verilog (mapcar 'cdr tlv-error-regexp-emacs-alist))
  "List of regexps for tools run in TL-Verilog mode.
See `compilation-error-regexp-alist-alist' for the formatting.  For XEmacs.")

(defvar tlv-error-font-lock-keywords
  (cons
    '("\\([A-Z_]*\\(ERROR\\|BUG\\|WARNING\\|INFORM\\)\\)" 1 bold t)
    verilog-error-font-lock-keywords)
  "Keywords to also highlight in TL-Verilog *compilation* buffers.
Only used in XEmacs; GNU Emacs uses `tlv-error-regexp-emacs-alist'.")


(if (featurep 'xemacs)
    ;; Following code only gets called from compilation-mode-hook on XEmacs to add error handling.
    (defun tlv-error-regexp-add-xemacs ()
      "Teach XEmacs about tl-verilog errors.
Called by `compilation-mode-hook'.  This allows \\[next-error] to
find the errors."
      (interactive)
(message "In tlv-error-regexp-add-emacs")
      (if (boundp 'compilation-error-regexp-systems-alist)
	  (if (and
	       (not (equal compilation-error-regexp-systems-list 'all))  ;; Do we have to do something here for TL-Verilog?
	       (not (member compilation-error-regexp-systems-list 'tl-verilog)))
	      (push 'tl-verilog compilation-error-regexp-systems-list)))
      (if (boundp 'compilation-error-regexp-alist-alist)
	  (if (not (assoc 'tl-verilog compilation-error-regexp-alist-alist))
	      (setcdr compilation-error-regexp-alist-alist
		      (cons tlv-error-regexp-xemacs-alist
			    (cdr compilation-error-regexp-alist-alist)))))
      (if (boundp 'compilation-font-lock-keywords)
	  (progn
	    (set (make-local-variable 'compilation-font-lock-keywords)
		 tlv-error-font-lock-keywords)
	    (font-lock-set-defaults)))
      ;; Need to re-run compilation-error-regexp builder
      (if (fboundp 'compilation-build-compilation-error-regexp-alist)
	  (compilation-build-compilation-error-regexp-alist))
      ))

;; Following code only gets called from compilation-mode-hook on Emacs to add error handling.
(defun tlv-error-regexp-add-emacs ()
   "Tell Emacs compile that we are TL-Verilog.
Called by `compilation-mode-hook'.  This allows \\[next-error] to
find the errors."
   (interactive)
   (if (boundp 'compilation-error-regexp-alist-alist)
       (progn
         (if (not (assoc 'sandpiper compilation-error-regexp-alist-alist))
             (mapcar
              (lambda (item)
                (push (car item) compilation-error-regexp-alist)
                (push item compilation-error-regexp-alist-alist)
                )
              tlv-error-regexp-emacs-alist)))))

;; Following suit of verilog-mode, but shouldn't these be buffer-local?
;; Using add-hook 3rd arg 'append' to order this last to the regexps take priority
;; over the others.  (Verilog-mode has a verilog-verbose regexp that hits on
;; sandpiper messages.)
(if (featurep 'xemacs) (add-hook 'compilation-mode-hook 'tlv-error-regexp-add-xemacs t))
(if (featurep 'emacs) (add-hook 'compilation-mode-hook 'tlv-error-regexp-add-emacs t))


(defcustom tl-verilog-mode-hook   'verilog-set-compile-command
  "Hook run after Verilog mode is loaded."
  :type 'hook
  :group 'tl-verilog-mode)


;; TL-Verilog key map.
(defvar tl-verilog-mode-map
  (let ((map (make-sparse-keymap)))
    (define-key map "\C-p"       'electric-tlv-scope-message)
    (define-key map [(shift right)] 'electric-tlv-indent-region)
    (define-key map [(shift left)] 'electric-tlv-unindent-region)
    (define-key map "\r"       'electric-tlv-terminate-line)
    ;; electric functions to override Verilog electric functions
    (define-key map ";"        'electric-tlv-semi)
    (define-key map ":"        'electric-tlv-colon)
    (define-key map "\`"       'electric-tlv-tick)
    map)
  "Keymap used in TL-Verilog mode.")


(setq tlv-font-lock-keywords
  (append
    (list

      ;; Fontify TL-Verilog constructs.

      ;; Fontify indentation
      '("^\\([ !]  \\)\\(   \\)*" 0 tlv-font-lock-indentation-face)

      ;; Fontify TL-Verilog identifiers
      '("^\\\\[A-Za-z0-9_]*" 0  tlv-font-lock-region-face)
      '("\\\\[A-Za-z0-9_]+_plus" 0 tlv-font-lock-local-region-face)
      '(">[A-Za-z][A-Za-z0-9_]*" 0 tlv-font-lock-beh-hier-face)
      '("|[A-Za-z][A-Za-z0-9_]*" 0 tlv-font-lock-pipeline-face)
      '("\\?[\\$\\*][A-Za-z][A-Za-z0-9_]*" 0 tlv-font-lock-when-face)
      '("\\$\\$?[A-Za-z][A-Za-z0-9_]*" 0 tlv-font-lock-pipesignal-face)
      '("\\*\\*?[A-Za-z][A-Za-z0-9_]*" 0 tlv-font-lock-sv-signal-face)
      '("\\^[A-Za-z][A-Za-z0-9_]*" 0 tlv-font-lock-attribute-face)
      '("%\\([+-][0-9]+\\|[A-Za-z0-9_]+\\)" 0 tlv-font-lock-alignment-face)
      '("#[+-][0-9]+" 0 tlv-font-lock-constant-face)   ;; TODO: Will need updates.
      '("@-?[0-9]+" 0 tlv-font-lock-stage-face)

      ;; Fontify TL-Verilog M4 constructs.
      '("m4_[A-Za-z0-9_]*" 0 tlv-font-lock-m4-macro-face)
      '("m4\\+[A-Za-z0-9_]*" 0 tlv-font-lock-m4-plus-macro-face))
    verilog-font-lock-keywords-3))   ;; From Verilog Mode



;;
;;
;;  Mode
;;
(defvar verilog-which-tool 1)
;;;###autoload
(define-derived-mode tl-verilog-mode verilog-mode "TL-Verilog"
  "Major mode for editing TL-Verilog code.
\\<tl-verilog-mode-map>
TL-Verilog mode extends Verilog mode.

All key bindings can be seen in a TL-Verilog-buffer with \\[describe-bindings].
Key bindings specific to `tl-verilog-mode-map' are:

\\{tl-verilog-mode-map}"
  :abbrev-table verilog-mode-abbrev-table
  ;; Set up for compilation
  (setq verilog-which-tool 1)
  (setq verilog-tool 'sandpiper)
  (verilog-set-compile-command)

  ;; Setting up menus
  ;;(when (featurep 'xemacs)
  ;;  (easy-menu-add verilog-stmt-menu)
  ;;  (easy-menu-add verilog-menu)
  ;;  (setq mode-popup-menu (cons "Verilog Mode" verilog-stmt-menu)))
  (when (featurep 'xemacs)
    (easy-menu-add tl-verilog-menu))

  ;; Stuff for GNU Emacs
  (set (make-local-variable 'font-lock-defaults)
       `((tlv-font-lock-keywords)
         nil nil nil
	 ,(if (functionp 'syntax-ppss)
	      ;; verilog-beg-of-defun uses syntax-ppss, and syntax-ppss uses
	      ;; font-lock-beginning-of-syntax-function, so
	      ;; font-lock-beginning-of-syntax-function, can't use
              ;; verilog-beg-of-defun.
	      nil
	    'verilog-beg-of-defun)))

;; Stuff from verilog-mode, that we don't seem to need.
;;  ;;------------------------------------------------------------
;;  ;; now hook in 'verilog-highlight-include-files (eldo-mode.el&spice-mode.el)
;;  ;; all buffer local:
;;  (unless noninteractive  ;; Else can't see the result, and change hooks are slow
;;    (when (featurep 'xemacs)
;;      (make-local-hook 'font-lock-mode-hook)
;;      (make-local-hook 'font-lock-after-fontify-buffer-hook); doesn't exist in Emacs
;;      (make-local-hook 'after-change-functions))
;;    (add-hook 'font-lock-mode-hook 'verilog-highlight-buffer t t)
;;    (add-hook 'font-lock-after-fontify-buffer-hook 'verilog-highlight-buffer t t) ; not in Emacs
;;    (add-hook 'after-change-functions 'verilog-highlight-region t t))
;;
;;  ;; Tell imenu how to handle Verilog.
;;  (set (make-local-variable 'imenu-generic-expression)
;;       verilog-imenu-generic-expression)
;;  ;; Tell which-func-modes that imenu knows about verilog
;;  (when (and (boundp 'which-func-modes) (listp which-func-modes))
;;    (add-to-list 'which-func-modes 'verilog-mode))
;;  ;; hideshow support
;;  (when (boundp 'hs-special-modes-alist)
;;    (unless (assq 'tl-verilog-mode hs-special-modes-alist)
;;      (setq hs-special-modes-alist
;;	    (cons '(tl-verilog-mode-mode  "\\<begin\\>" "\\<end\\>" nil
;;				       verilog-forward-sexp-function)
;;		  hs-special-modes-alist))))
;;
;;  ;; Stuff for autos
;;  (add-hook 'write-contents-hooks 'verilog-auto-save-check nil 'local)
;;  ;; tl-verilog-mode-hook call added by define-derived-mode
  )



;; menus
(easy-menu-define
  tl-verilog-menu tl-verilog-mode-map "Menu for TL-Verilog mode"
  (verilog-easy-menu-filter
   '("TL-Verilog"
     "<<This menu is pre-beta!>>"
     ("Choose Compilation Action"
      ["None"
       (progn
	 (setq verilog-tool nil)
	 (verilog-set-compile-command))
       :style radio
       :selected (equal verilog-tool nil)
       :help "When invoking compilation, use compile-command"]
      ["Simulator"
       (progn
	 (setq verilog-tool 'verilog-simulator)
	 (verilog-set-compile-command))
       :style radio
       :selected (equal verilog-tool `verilog-simulator)
       :help "When invoking compilation, interpret Verilog source"]
      ["Compiler"
       (progn
	 (setq verilog-tool 'verilog-compiler)
	 (verilog-set-compile-command))
       :style radio
       :selected (equal verilog-tool `verilog-compiler)
       :help "When invoking compilation, compile Verilog source"]
      ["Preprocessor"
       (progn
	 (setq verilog-tool 'verilog-preprocessor)
	 (verilog-set-compile-command))
       :style radio
       :selected (equal verilog-tool `verilog-preprocessor)
       :help "When invoking compilation, preprocess Verilog source, see also `verilog-preprocess'"]
     )
     "----"
     ["Compile"				compile
      :help		"Perform compilation-action (above) on the current buffer"]
     ["AUTO, Save, Compile"		verilog-auto-save-compile
      :help		"Recompute AUTOs, save buffer, and compile"]
     ["Next Compile Error"		next-error
      :help		"Visit next compilation error message and corresponding source code"]
     "----"
     ["Indent region"			electric-tlv-indent-region
      :help		"Indent lines of selected region or cursor by one level, and display scope of beginning of region"]
     ["Un-indent region"		electric-tlv-unindent-region
      :help		"Unindent lines of selected region or cursor by one level, and display scope of beginning of region"]
     ["What's my scope?"		electric-tlv-scope-message
      :help		"Display TL-Verilog scope of cursor"]
     "----"
     ["Submit bug report"		tl-verilog-submit-bug-report
      :help		"Submit via mail a bug report on verilog-mode.el"]
     ["Version and FAQ"			tl-verilog-faq
      :help		"Show the current version, and where to get the FAQ etc"]
     ["Customize Verilog Mode..."	tl-verilog-customize
      :help		"Customize variables and other settings used by Verilog-Mode"]
     ["Customize Verilog Fonts & Colors"	tl-verilog-font-customize
      :help		"Customize fonts used by TL-Verilog-Mode."]
)))






;; ==============
;; TL-Verilog Electric function helpers
;;




;; -----------
;; Indentation
;; -----------

;; TLV get indentation.
(defun tlv-get-indentation(&optional max-arg)
  "Return the number of indentation characters in the current line,
assuming TLV-context, up to a maximum of max-arg.  Indentation
includes the line prefix char and spaces to eol or to non-space.
Return value is negated for empty lines (so <= 0 for empty lines).
If indentation exceeds max-arg, max-arg is returned, whether or not
the line is empty."
  (save-excursion
    ;; Start at beginning of line, then scan over prefix
    ;; character and spaces.  Return number of spaces or negative
    ;; number of spaces if eol reached.
    (forward-line 0)
    (let ((max (if max-arg max-arg 1000))
          (start (point)) ;; beginning of line
          (ind 1))        ;; indent chars count, after line prefix char
      ;; Skip line prefix char.
      (if (eolp)
        ;; Line empty. Return 0.
        0
        ;; Line not empty. Scan past line prefix char.
        (progn
          (forward-char)  ;; Skip line prefix.
          ;; Scan past spaces.
          (while (and (= (char-after) ?\ ) (< ind max))
            (progn
              (forward-char)          ;; next char
              (setq ind (1+ ind))))   ;; count it
          ;; Return indentation or negative empty line indentation.
          (if (eolp)
            (- ind)
            ind))))))


;; TLV empty-line.
(defun tlv-empty-line-p()
  "Return t if current line is empty."
  (<= (tlv-get-indentation) 0))


;; TLV Indent/Unindent Line.
(defun tlv-indent-line(delta)
  "TLV indent/unindent line"
  (interactive)
  (save-excursion
    (forward-line 0)
    (unless (eolp)
      ;; Non-empty line

      ;; Skip line prefix char.
      (when (tlv-line-prefix-p (char-after))
        (forward-char))

      (if (>= delta 0)
        ;; Indent
        (dotimes (cnt delta)
          (insert-string " "))
        ;; Un-indent
        (dotimes (cnt (- delta))
          (when (= (char-after) ?\ )
            (delete-char 1)))))))


;; TLV Indent/Unindent Region or line if no region selected.
;; Display new scope of (region-beginning).
(defun tlv-indent-region (delta)
  "TLV indent/un-indent region"
  (interactive)
  (save-excursion
    (if (region-active-p) ;; (use-region-p) is not recognized by XEmacs.
      ;; Region selected.
      ;; Iterate from end (pt2) to beginning (pt1).
      (let ((pt1 (region-beginning))
            (pt2 (- (region-end) 1)))   ;; -1 excludes line beginning at region-end.
        (let (deactivate-mark)  ;; Do not deactivate region afterward.
          (goto-char pt2)
          (forward-line 0)
          (tlv-indent-line delta)
          (while (> (point) pt1)
            (forward-line -1)
            (tlv-indent-line delta))))
      ;; no region selected
      (tlv-indent-line delta))
    ;; Display scope at 'point', which is now on first selected line.
    (electric-tlv-scope-message)))


;; -----
;; Scope
;; -----

;; TLV line prefix character test.
(defun tlv-line-prefix-p(ch)
  "Return t if char is a valid TLV line prefix character."
  (or (= ch ?\ )
      (= ch ?\!)))

;; TLV scope prefix character test.
(defun tlv-scope-prefix-p(ch)
  "Return t if char is a valid TLV scope prefix character."
  (or (= ch ?\>)
      (= ch ?\|)
      (= ch ?\@)
      (= ch ?\?)
      (= ch ?\\)))


;; TLV get scope identifier on this line.
(defun tlv-get-scope-ident(&optional max-len)
  "Find the next string with no whitespace on this line and return it.
If it doesn't look like a scope identifier surround it in {}.  If it
exceeds max-len, truncate it and extend with '...'."
  ;; Search for scope identifier string.
  (re-search-forward
    ;; Find string of non-whitespace followed by optional [...] (not [... // ])
    "[^ \t\n\\[]+\\(\\[[^\\(//\\)]*\\]\\)?"
    (save-excursion (end-of-line) (point))  ;; end of line pos
    t)
  ;; With ident = scope identifier string matched above:
  (let ((ident (match-string 0)))
    ;; Truncate if over max-len.
    (when (and max-len (> (length ident) max-len))
      (setf ident (substring ident 0 max-len)))
    ;; Return it, but if it doesn't look like a scope identifier,
    ;; return it inside {}.
    (if (string-match "^[\\>|?@]" ident)
      ident
      (concat (propertize "{" 'face 'tlv-font-lock-bad-scope-face)
              ident
              (propertize "}" 'face 'tlv-font-lock-bad-scope-face)))))


(defconst tlv-max-scope-search 1000
  "Non-nil sets an upper bound on the number of lines that
will be searched to determine TLV scope.")


;; Move point up to parent scope line.
(defun tlv-up-to-parent-scope(ind line-cnt)
  "Find line of parent scope.
With point at the beginning of a line, move point upward while
we are not on a line with less indentation than 'ind' and we have
not reached the search limit line count.  line-cnt is passed in and is
incremented for each line searched.  Multiple values are returned
\(scope-str ind line-cnt\).  'scope-str' is the string
representing the parent scope.  It is enclosed in [] if not
recognized as proper scope.  'ind' and 'line-cnt' are updates of
the parameters to this function.  'ind' and 'line-cnt' are returned as nil if
tlv-max-scope-search is exceeded.  'point' is left at the line of the
parent scope, at the scope identifier if found, otherwise at the
beginning of line."

  ;; Scan lines upward.
  (while (progn
           (setq line-ind (tlv-get-indentation ind))
           ;; line-ind is indentation to max of 'ind'.
           ;; Continue while not lesser indentation and not at max lines.
           (and (or (>= line-ind ind)               ;; >= indentation
                    (<= line-ind 0))                ;; empty line
                (< line-cnt tlv-max-scope-search))) ;; not max lines searched
    (forward-line -1)               ;; Go to next line up.
    (setq line-cnt (1+ line-cnt)))  ;; Count it.

  ;; Return list of three values
  (if (or (>= line-ind ind) (<= line-ind 0))
    ;; Failed to find scope.
    (list "..." nil nil)
    ;; Found scope.
    (list
      ;; scope identifier:
      (progn
        (forward-char line-ind)       ;; Go to scope identifier.
        (let ((ident (tlv-get-scope-ident 20)))  ;; Get identifier.
          ;; Append highlighted "(!)" if indentation isn't 3 spaces.
          (if (= line-ind (- ind 3))
            ident
            (concat ident (propertize "!" 'face 'tlv-font-lock-bad-indentation-face)))))
      line-ind
      line-cnt)))


;; TLV get scope string.
(defun tlv-get-scope-string()
  "Return a string (with text properties) representing the TLV scope
of the current line."
  (save-excursion
    (let ((scope-str "")                        ;; scope string to return
          (line-cnt 1)                          ;; line count for scope search
          (line-ind (tlv-get-indentation 100))) ;; indentation of current line
      (forward-line -1)     ;; Begin search at line above 'point'.
      (while (> line-ind 3)  ;; While inside scope below \TLV scope w/
                             ;;   3 space indentation.
        ;; Find parent scope and extract return values.
        (setq tmp-ret (tlv-up-to-parent-scope line-ind line-cnt))
        (setq scope-str (concat (pop tmp-ret) scope-str))
        (setq line-ind (pop tmp-ret))
        (setq line-cnt (pop tmp-ret)))
      scope-str)))





;;
;;  Electric functions
;;


;; TLV Indent one level all lines of a region or line of point.
(defun electric-tlv-indent-region()
  "TLV indent region"
  (interactive)
  (tlv-indent-region 3))


;; TLV Unindent one level all lines of a region or line of point.
(defun electric-tlv-unindent-region()
  "TLV un-indent region"
  (interactive)
  (tlv-indent-region -3))


;; TLV electric new-line function to indent a new line.
(defun electric-tlv-terminate-line()
  "TLV electric new-line function to indent a new line.  Indentation is spaces
matching previous line or 3 spaces more if previous line is a scope line."
  (interactive)
  (save-excursion
    (newline))
  (forward-line 0)
  (let ((pos-above (point)))  ;; pos-above = point above beginning of new line
    (forward-line)
    ;; Insert line prefix char space (if char is a line prefix char).
    (when (tlv-line-prefix-p (char-after pos-above))
      (progn
        (insert ?\ )
        (setq pos-above (1+ pos-above))))
    ;; Insert spaces as long as the char above is a space.
    (while (= (char-after pos-above) ?\ )
      (insert ?\ )
      (setq pos-above (1+ pos-above)))
    ;; Indent if above line is a scope line.
    (when (tlv-scope-prefix-p (char-after pos-above))
      (insert-string "   "))))

(defun electric-tlv-semi()
  "TLV electric function for semi-colon to do nothing."
  (interactive)
  (verilog-insert-last-command-event)
)
(defun electric-tlv-colon()
  "TLV electric function for colon to do nothing."
  (interactive)
  (verilog-insert-last-command-event)
)
(defun electric-tlv-tick()
  "TLV electric function for back-tick to do nothing."
  (interactive)
  (verilog-insert-last-command-event)
)

(defun electric-tlv-scope-message()
  "TLV display current scope as message using (tlv-get-scope-string)."
  (interactive)
  (message (concat "Scope: " (tlv-get-scope-string))))



;;
;; Bug reporting
;;

(defun tl-verilog-faq ()
  "Tell the user their current version, and where to get the FAQ etc."
  (interactive)
  (with-output-to-temp-buffer "*tl-verilog-mode help*"
    (princ (format "You are using tl-verilog-mode %s\n" tl-verilog-mode-version))
    (princ "\n")
    (princ "For new releases, see http://www.verilog.com\n")
    (princ "\n")
    (princ "For frequently asked questions, see http://www.veripool.org/tl-verilog-mode-faq.html\n")
    (princ "\n")
    (princ "To submit a bug, use M-x tl-verilog-submit-bug-report\n")
    (princ "\n")))

(autoload 'reporter-submit-bug-report "reporter")
(defvar reporter-prompt-for-summary-p)

(defun tl-verilog-submit-bug-report ()
  "Submit via mail a bug report on tl-verilog-mode.el."
  (interactive)
  (let ((reporter-prompt-for-summary-p t))
    (reporter-submit-bug-report
     "steve.hoover@rweda.com"
     (concat "tl-verilog-mode v" tl-verilog-mode-version)
     '(
       verilog-active-low-regexp
       verilog-after-save-font-hook
       verilog-align-ifelse
       verilog-assignment-delay
       verilog-auto-arg-sort
       verilog-auto-declare-nettype
       verilog-auto-delete-trailing-whitespace
       verilog-auto-endcomments
       verilog-auto-hook
       verilog-auto-ignore-concat
       verilog-auto-indent-on-newline
       verilog-auto-inout-ignore-regexp
       verilog-auto-input-ignore-regexp
       verilog-auto-inst-column
       verilog-auto-inst-dot-name
       verilog-auto-inst-interfaced-ports
       verilog-auto-inst-param-value
       verilog-auto-inst-sort
       verilog-auto-inst-template-numbers
       verilog-auto-inst-vector
       verilog-auto-lineup
       verilog-auto-newline
       verilog-auto-output-ignore-regexp
       verilog-auto-read-includes
       verilog-auto-reset-blocking-in-non
       verilog-auto-reset-widths
       verilog-auto-save-policy
       verilog-auto-sense-defines-constant
       verilog-auto-sense-include-inputs
       verilog-auto-star-expand
       verilog-auto-star-save
       verilog-auto-template-warn-unused
       verilog-auto-tieoff-declaration
       verilog-auto-tieoff-ignore-regexp
       verilog-auto-unused-ignore-regexp
       verilog-auto-wire-type
       verilog-before-auto-hook
       verilog-before-delete-auto-hook
       verilog-before-getopt-flags-hook
       verilog-before-save-font-hook
       verilog-cache-enabled
       verilog-case-fold
       verilog-case-indent
       verilog-cexp-indent
       verilog-compiler
       verilog-coverage
       verilog-delete-auto-hook
       verilog-getopt-flags-hook
       verilog-highlight-grouping-keywords
       verilog-highlight-includes
       verilog-highlight-modules
       verilog-highlight-p1800-keywords
       verilog-highlight-translate-off
       verilog-indent-begin-after-if
       verilog-indent-declaration-macros
       verilog-indent-level
       verilog-indent-level-behavioral
       verilog-indent-level-declaration
       verilog-indent-level-directive
       verilog-indent-level-module
       verilog-indent-lists
       verilog-library-directories
       verilog-library-extensions
       verilog-library-files
       verilog-library-flags
       verilog-linter
       verilog-minimum-comment-distance
       tl-verilog-mode-hook
       tl-verilog-mode-release-emacs
       tl-verilog-mode-version
       verilog-preprocessor
       verilog-simulator
       verilog-tab-always-indent
       verilog-tab-to-comment
       verilog-typedef-regexp
       verilog-warn-fatal
       )
     nil nil
     (concat "Hi Steve,

I want to report a bug in the Emacs TL-Verilog Mode.

Before I go further, I want to say that TL-Verilog has changed my life.
I'd really appreciate anything you could do to help me out with this
minor deficiency.

I recognize that TL-Verilog Mode is built upon Verilog Mode, and that
Verilog Mode bugs should be reported via different channels.  I have
done due diligence to determine that this issue does not exist in
Verilog Mode.  I have attempted to reproduce the issue in Verilog Mode
using the Verilog code generated from my TL-Verilog code and am unable
to do so.  This is not an issue with the SandPiper(TM) tool, but rather
with the Emacs mode specifically.

This issue exists in the latest version of the TL-Verilog Mode
available via redwoodeda.com.

To reproduce the bug, start a fresh Emacs via " invocation-name "
-no-init-file -no-site-file'.  In a new buffer, in TL-Verilog mode, type
the code included below.

Given those lines, I expected [[Fill in here]] to happen;
but instead, [[Fill in here]] happens!.

== The code: =="))))

(provide 'tl-verilog-mode)

;; Local Variables:
;; checkdoc-permit-comma-termination-flag:t
;; checkdoc-force-docstrings-flag:nil
;; End:

;;; tl-verilog-mode.el ends here
