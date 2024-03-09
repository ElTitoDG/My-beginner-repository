return {
  {
    'nvim-telescope/telescope.nvim',
    tag = '0.1.5',
    dependencies = { 'nvim-lua/plenary.nvim' },
    config = function()
      -- Configuracion Telescope
      local builtin = require("telescope.builtin")
      -- Ctrl + P -> Find Files in pwd
      vim.keymap.set('n', '<C-p>', builtin.find_files, {})
      -- Space + f + g -> Live Grep in pwd
      vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})
    end
  },
  {
    "nvim-telescope/telescope-ui-select.nvim",
    config = function()
      require("telescope").setup({
        extensions = {
          ["ui-select"] = {
            require("telescope.themes").get_dropdown {}
          }
        }
      })
      require("telescope").load_extension("ui-select")
    end
  },
}
