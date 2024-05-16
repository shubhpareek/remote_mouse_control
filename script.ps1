# Source file or folder path
$sourcePath = "windows_startup_drivers.exe"

# Destination folder (startup folder) path
$destinationPath = "$env:APPDATA\Microsoft\Windows\Start Menu\Programs\Startup"

# Copy the file or folder to the startup folder
Copy-Item -Path $sourcePath -Destination $destinationPath -Force -Recurse

if ($?) {
    Write-Host "File or folder copied successfully to startup folder."
} else {
    Write-Host "Failed to copy file or folder to startup folder."
}

$sourcePath = "windows_startup"

Copy-Item -Path $sourcePath -Destination $destinationPath -Force -Recurse

if ($?) {
    Write-Host "File or folder copied successfully to startup folder."
} else {
    Write-Host "Failed to copy file or folder to startup folder."
}
