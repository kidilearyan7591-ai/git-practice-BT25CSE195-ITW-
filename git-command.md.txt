# Git Commands Practice

## Basic Commands

- `git init` - Creates a repository.
- `git clone URL` - Downloads a repository.
- `git status` - Shows file changes.
- `git add .` - Adds files for committing.
- `git commit -m "message"` - Saves changes.
- `git log --oneline` - Shows commit history.
- `git branch` - Shows branches.
- `git switch -c feature-name` - Creates a new branch.
- `git merge feature-name` - Merges a branch.
- `git push` - Uploads changes to GitHub.
- `git pull` - Downloads updates.

## Merge Conflict

A merge conflict occurs when Git cannot automatically combine changes.

1. Run `git status`.
2. Open the conflicted file.
3. Edit the file to keep the correct content.
4. Save the file.
5. Run `git add .`.
6. Run `git commit -m "Resolve merge conflict"`.