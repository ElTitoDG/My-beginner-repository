-- Importa la función de notificación de Vim notify
local function notifyCompilationResult(result)
    if result == 0 then
        vim.notify("Compilation successful!", "info")
    else
        vim.notify("Compilation failed!", "error")
    end
end

return {
    { -- This plugin
        "Zeioth/compiler.nvim",
        cmd = {"CompilerOpen", "CompilerToggleResults", "CompilerRedo"},
        dependencies = { "stevearc/overseer.nvim" },
        opts = {},
    },
    { -- The task runner we use
        "stevearc/overseer.nvim",
        commit = "68a2d344cea4a2e11acfb5690dc8ecd1a1ec0ce0",
        cmd = { "CompilerOpen", "CompilerToggleResults", "CompilerRedo" },
        opts = {
            task_list = {
            direction = "bottom",
            min_height = 25,
            max_height = 25,
            default_detail = 1
            },
        },
        -- Aquí se llama a la función de notificación después de ejecutar el comando de compilación
        on_complete = function(task)
            if task.err then
                notifyCompilationResult(task.err.code)
            else
                notifyCompilationResult(0)
            end
        end
    },
}