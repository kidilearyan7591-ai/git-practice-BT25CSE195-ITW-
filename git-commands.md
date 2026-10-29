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
## Merge Conflict Example

A merge conflict happens when Git cannot automatically combine changes made to the same part of a file.

To resolve a conflict:
1. Run `git status` to find the conflicted file.
2. Open the file and choose the correct content.
3. Remove conflict markers and save the file.
4. Run `git add filename`.
5. Run `git commit -m "Resolve merge conflict"`.

This documents the steps used to identify and resolve a merge conflict.
