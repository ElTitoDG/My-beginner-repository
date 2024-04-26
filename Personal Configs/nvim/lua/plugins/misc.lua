-- lua/plugins/misc.lua
-- misc plugins

return {
    -- Toggleterm
    {
        "akinsho/toggleterm.nvim",
        version = "*",
        config = true
    },

    -- LazyGit
    {
        "kdheepak/lazygit.nvim",
    },

    -- File explorer
    {
        "nvim-tree/nvim-tree.lua",
        version = "*",
        lazy = false,
        dependencies = {
          "nvim-tree/nvim-web-devicons",
        },
        config = function()
          require("nvim-tree").setup()
        end,
    },

    {
        "coffebar/neovim-project",
        opts = {
          projects = { -- define project roots
            "~/Documents/Dev/*",
            "~/CLionProjects/*",
            "~/.config/*",
          },
          dashboard_mode = true,
        },
        init = function()
          -- enable saving the state of plugins in the session
          vim.opt.sessionoptions:append("globals") -- save global variables that start with an uppercase letter and contain at least one lowercase letter.
        end,
        dependencies = {
          { "nvim-lua/plenary.nvim" },
          { "nvim-telescope/telescope.nvim"},
          { "Shatur/neovim-session-manager" },
        },
        lazy = false,
        priority = 100,
    },

    {
        "matbme/JABS.nvim",
        config = function ()
            local jabs = require("jabs")

            jabs.setup({
                -- config
                position = { 'center', 'top' },
            })
        end
    },

    -- Which-key
    {
        "folke/which-key.nvim",
        config = function ()
            local wk = require("which-key")

            wk.register({
                ["<leader>f"] = {
                    name = "+file",
                    f = { "<cmd>Telescope find_files<cr>", "Find File" },
                    r = { "<cmd>Telescope oldfiles<cr>", "Open Recent File" },
                    s = { "<cmd>w<cr>", "Save File"},
                    w = { "<cmd>Telescope live_grep<cr>", "Find Word" },
                },

                ["<leader>b"] = {
                    name = "+buffer",
                    b = { "<cmd>Telescope buffers<cr>", "Find Buffer" },
                    c = { "<cmd>bd<cr>", "Close Buffer" },
                    j = { "<cmd>JABSOpen<cr>", "Open JABS" },
                },

                ["<leader>t"] = {
                    name = "+ToggleTerm",
                    f = { "<cmd>ToggleTerm direction=float<cr>", "Float" },
                    h = { "<cmd>ToggleTerm size=10 direction=horizontal<cr>", "Horizontal" },
                    v = { "<cmd>ToggleTerm size=80 direction=vertical<cr>", "Vertical" },
                    g = { "<cmd>LazyGit<cr>", "LazyGit" },
                },

                ["<leader>c"] = {
                    name = "+compiler",
                    o = { "<cmd>CompilerOpen<cr>", "Open Compiler" },
                    t = { "<cmd>CompilerToggleResults<cr>", "Toggle Compiler Results" },
                    r = { "<cmd>CompilerRedo<cr>", "Redo Compiler" },
                },

                ["<leader>e"] = { "<cmd>NvimTreeToggle<cr>", "Toggle NvimTree" },
                ["<leader>d"] = { "<cmd>Dashboard<cr>", "Open Dashboard" },
                ["<leader>m"] = { "<cmd>Mason<cr>", "Open Mason" },
                ["<leader>q"] = { "<cmd>q<cr>", "Quit" },
            })
        end
    },


    {
        "cohama/lexima.vim"
    },

}
