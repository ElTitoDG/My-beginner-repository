-- lua/plugins/theme.lua
-- Theme configurations

return {
    -- Oxocarbon theme
    {
        "nyoom-engineering/oxocarbon.nvim",
        -- Add in any other configuration; 
        name = "oxocarbon",
        lazy = false,
        priority = 1000,
        config = function()
            vim.cmd.colorscheme "oxocarbon"
        end
    },

    -- Dashboard
    {
        "nvimdev/dashboard-nvim",
        event = 'VimEnter',
        config = function()
            require('dashboard').setup {
                -- config
                config = {
                    header = {
                        -- Dashboard header
                        " ███╗   ██╗ ███████╗ ██████╗  ██╗   ██╗ ██╗ ███╗   ███╗",
                        " ████╗  ██║ ██╔════╝██╔═══██╗ ██║   ██║ ██║ ████╗ ████║",
                        " ██╔██╗ ██║ █████╗  ██║   ██║ ██║   ██║ ██║ ██╔████╔██║",
                        " ██║╚██╗██║ ██╔══╝  ██║   ██║ ╚██╗ ██╔╝ ██║ ██║╚██╔╝██║",
                        " ██║ ╚████║ ███████╗╚██████╔╝  ╚████╔╝  ██║ ██║ ╚═╝ ██║",
                        " ╚═╝  ╚═══╝ ╚══════╝ ╚═════╝    ╚═══╝   ╚═╝ ╚═╝     ╚═╝",
                    },
                }
            }
        end,
        dependencies = {
          "nvim-tree/nvim-web-devicons",
        }
    },

    {
        "rcarriga/nvim-notify"
    }
}
