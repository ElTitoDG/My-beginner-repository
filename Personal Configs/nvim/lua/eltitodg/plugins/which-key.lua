return {
	"folke/which-key.nvim",
	event = "VeryLazy",
	init = function ()
		vim.o.timeout = true
		vim.o.timeoutlen = 500
	end,
	config = function ()
		local wk = require("which-key")

		wk.add({
			-- ToggleTerm Group Keybinds
			{ "<leader>t", group = "ToggleTerm"},
			{ "<leader>tf", "<cmd>ToggleTerm direction=float<cr>", desc = "Float", mode = "n" },
			{ "<leader>th", "<cmd>ToggleTerm direction=horizontal<cr>", desc = "Horizontal", mode = "n" },
			{ "<leader>tv", "<cmd>ToggleTerm direction=vertical<cr>", desc = "Vertical", mode = "n" },
    			{ "<leader>tg", "<cmd>LazyGit<cr>", desc = "Open lazy git" },


			-- Nvim-Tree Group
			{ "<leader>e", group = "File Explorer" },
			{ "<leader>et", "<cmd>NvimTreeToggle<cr>", desc = "Toggle file explorer" },
			{ "<leader>ef", "<cmd>NvimTreeFindFileToggle<cr>", desc = "Toggle file explorer on current file" },
			{ "<leader>ec", "<cmd>NvimTreeCollapse<cr>", desc = "Collapse file explorer" },
			{ "<leader>er", "<cmdNvimTreeRefresh<cr>", desc = "Refresh file explorer" },

			-- Telescope Group
			{ "<leader>f", group = "Find" },
			{ "<leader>ff", "<cmd>Telescope find_files<cr>", desc = "Fuzzy find files in cwd" },
			{ "<leader>fr", "<cmd>Telescope oldfiles<cr>", desc = "Fuzzy find recent files" },
			{ "<leader>fs", "<cmd>Telescope live_grep<cr>", desc = "Find string in cwd" },
			{ "<leader>fc", "<cmd>Telescope grep_string<cr>", desc = "Find string under cursor in cwd" },
			{ "<leader>ft", "<cmd>TodoTelescope<cr>", desc = "Find todos" },

			-- Close NeoVim
			{ "<leader>q", "<cmd>qa<cr>", desc = "Exit Neovim" },

			-- Code Group
			{ "<leader>c", group = "Code" },
			{ "<leader>cL", "<cmd>LspInfo<cr>", desc = "Lsp Info" },

			-- Code Buffer
			{ "<leader>b", group = "Buffer" }
		})
	end

}
