# i3 Window Manager Keybindings Cheat Sheet

**$mod Key:** Command Key (Mac), Windows Key (Windows)

## General

- Start a terminal: `$mod+Return` => `kitty`
- Start Firefox: `$mod+w` => `firefox`
- Kill focused window: `$mod+q` => Kill

## Window Management

- Move floating windows: `$mod + Mouse drag`
- General settings for floating windows: (450x450 min, 1920x1080 max)

## Navigation

- Change focus (arrow keys): 
  - `$mod+h` => Left
  - `$mod+j` => Down
  - `$mod+k` => Up
  - `$mod+l` => Right
- Move focused window (arrow keys): 
  - `$mod+Shift+h` => Left
  - `$mod+Shift+j` => Down
  - `$mod+Shift+k` => Up
  - `$mod+Shift+l` => Right
- Split horizontally: `$mod+comma` => Split H
- Split vertically: `$mod+v` => Split V
- Toggle fullscreen: `$mod+f` => Fullscreen
- Change container layout: 
  - `$mod+s` => Stacked
  - `$mod+t` => Tabbed
  - `$mod+e` => Toggle Split
- Toggle tiling/floating: `$mod+Shift+space` => Toggle Floating
- Change focus between tiling/floating windows: `$mod+space` => Mode Toggle
- Focus parent/child containers: 
  - `$mod+a` => Focus Parent
  - `$mod+c` => Focus Child
- Enter resize mode: `$mod+r` => Resize

## Workspaces

- Switch to workspace: 
  - `$mod+1` to `$mod+0` => Workspace number $ws1 to $ws10
- Move focused container to workspace: 
  - `$mod+Shift+1` to `$mod+Shift+0`

## Configuration

- Reload the configuration file: `$mod+Shift+c` => Reload
- Restart i3 in place: `$mod+Shift+r` => Restart
- Exit i3: `$mod+Shift+e` => Exit i3

## Screenshots

- Take full screen screenshot: `Print` => Save to file
- Take screenshot of the current window: `$mod+Print` => Save to file
- Select a region for a screenshot: `Shift+Print` => Save to file
- Copy full screen screenshot to clipboard: `Ctrl+Print` => Copy to clipboard
- Copy screenshot of the current window to clipboard: `Ctrl+$mod+Print` => Copy to clipboard
- Copy selected region screenshot to clipboard: `Ctrl+Shift+Print` => Copy to clipboard

## Display Settings

- Set wallpaper with feh: Automatically loads 'flowers.png'
- Enable Picom compositor for effects: `picom`
- Start Polybar: `$HOME/.config/polybar/launch.sh`
- Adjust display temperature with Redshift
