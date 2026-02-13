$ErrorActionPreference = "Stop"

Write-Host "==== Git Hard Reset Script ====" -ForegroundColor Yellow

# Ensure we're inside a git repo
git rev-parse --is-inside-work-tree > $null 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-Host "Not inside a git repository!" -ForegroundColor Red
    exit 1
}

# Detect current branch automatically
$branch = git branch --show-current
Write-Host "Current branch: $branch" -ForegroundColor Cyan

Write-Host "Fetching latest from origin..."
git fetch origin

Write-Host "Resetting to origin/$branch ..."
git reset --hard "origin/$branch"

Write-Host "Cleaning untracked files..."
git clean -fd

Write-Host "✅ Repo now matches origin/$branch exactly." -ForegroundColor Green
