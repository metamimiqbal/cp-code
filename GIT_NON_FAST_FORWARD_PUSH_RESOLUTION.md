# Git Non-Fast-Forward Push Resolution

## Issue Query

How do I resolve a rejected Git push when `git push -u origin master` fails because the remote branch contains commits that are not present in my local branch?

Related error:

```bash
! [rejected] master -> master (non-fast-forward)
error: failed to push some refs
hint: Updates were rejected because the remote contains work that you do not have locally.
```

## Cause

The local `master` branch and the remote `origin/master` branch had diverged.

In this case:

- The local branch was clean.
- The local branch was ahead of `origin/master` by 3 commits.
- The remote branch was ahead of the local branch by 1 commit.

Because the remote had a commit that was missing locally, Git rejected the push to prevent overwriting remote history.

## Resolution

First, inspect the current branch and remote setup:

```bash
git status --short --branch
git remote -v
git branch -vv
```

Then inspect recent local and remote history:

```bash
git log --oneline --decorate --graph --max-count=12 --all
```

Try pushing to confirm the exact server-side error:

```bash
git push -u origin master
```

If the push is rejected because the remote contains work that is not present locally, fetch the latest remote state:

```bash
git fetch origin
```

Check the branch status again:

```bash
git status --short --branch
git log --oneline --decorate --graph --max-count=20 --all
```

If Git shows that the branch is both ahead and behind, merge the remote branch into the local branch:

```bash
git merge origin/master
```

In this case, the merge completed cleanly and Git created a merge commit. After that, push again:

```bash
git push -u origin master
```

## Final Result

The second push succeeded after merging `origin/master` into the local `master` branch. The local branch now tracks `origin/master`, and the remote branch contains both the remote README update and the local commits.

## Short Recipe

Use this sequence when a push is rejected because the remote branch has new commits:

```bash
git status
git fetch origin
git log --oneline --graph --decorate --all
git merge origin/master
git push -u origin master
```

Alternative:

```bash
git pull --rebase origin master
git push -u origin master
```

Use the rebase option when you prefer a linear history and have not already shared your local commits with others.
