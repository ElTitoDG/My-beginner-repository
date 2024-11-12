return {
	--[[ "nyoom-engineering/oxocarbon.nvim",
	priority = 1000,
  	config = function()
		vim.opt.background = "dark"

		vim.cmd("colorscheme oxocarbon")

		vim.api.nvim_set_hl(0, "Normal", {bg = "none"})
		vim.api.nvim_set_hl(0, "NormalFloat", {bg = "none"})
		vim.api.nvim_set_hl(0, "NormalNC", {bg = "none"})
	end, ]]
	"rebelot/kanagawa.nvim",
	priority = 1000,
	config = function ()
		require("kanagawa").setup({
			transparent = true,
		})

		vim.cmd("colorscheme kanagawa")
	end
}
