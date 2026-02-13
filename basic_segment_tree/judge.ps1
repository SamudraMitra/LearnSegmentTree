# Stop script on first error
$ErrorActionPreference = "Stop"

function Compile-And-Run($file) {
    $name = [System.IO.Path]::GetFileNameWithoutExtension($file)

    Write-Host "========== $name =========="

    g++ $file -std=c++17 -O2 -o "$name.exe"

    if ($LASTEXITCODE -ne 0) {
        Write-Host "Compilation failed for $file"
        exit 1
    }

    .\("$name.exe")
    Write-Host ""
}

Compile-And-Run "GeneralizedSegmentTree.cpp"
Compile-And-Run "SegmentTree.cpp"
