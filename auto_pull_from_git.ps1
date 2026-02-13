$ErrorActionPreference = "Stop"

Write-Host "==== Git Hard Reset Script ====" -ForegroundColor Yellow


# Detect current branch
$branch = git branch --show-current
Write-Host "Current branch: $branch" -ForegroundColor Cyan

Write-Host "Fetching latest from origin..."
git fetch origin

Write-Host "Resetting to origin/$branch ..."
git reset --hard "origin/$branch"

Write-Host "Cleaning untracked files..."
git clean -fd

Write-Host "✅ Repo now matches origin/$branch exactly." -ForegroundColor Green
s