return {
	{
		"williamboman/mason.nvim",
		config = function()
			require("mason").setup()
		end,
	},
	{
		"williamboman/mason-lspconfig.nvim",
		config = function()
			require("mason-lspconfig").setup()
		end,
	},
	{
		"VonHeikemen/lsp-zero.nvim",
		dependencies = {
			{"neovim/nvim-lspconfig"},
			{"williamboman/mason-lspconfig.nvim"},
		},
		config = function()
			local lsp_zero = require("lsp-zero")
			lsp_zero.extend_lspconfig()

			local capabilities = require("cmp_nvim_lsp").default_capabilities()

			local lspconfig = require("lspconfig")

			local mason_lspconfig = require "mason-lspconfig"

			mason_lspconfig.setup_handlers {
				function(server_name)
					lspconfig[server_name].setup {
						capabilities = capabilities,
					}
				end,
			}

			lsp_zero.on_attach(function(client, bufnr)
				lsp_zero.default_keymaps({ buffer = bufnr })
			end)

			mason_lspconfig.setup {
				ensure_installed = { "lua_ls", "pyright", "clangd", "tsserver", "cmake" },
			}

			lsp_zero.setup {}
		end,
	},
}
