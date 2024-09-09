***clone***: The clone command is used to copy (download) data from remote repositories such as GitHub, GitLab... to a local repository.
```
git clone <repository url>
```

***commit***: The commit command is used to record (save) changes to the data into Git's history. Each commit corresponds to a snapshot of the data created along with a description from the person making the commit.
```
git commit -m "commit message"
```

***push***: The push command is used to push (send) commits from the local repository to the remote repository.
```
# Push commits to the specified branch
git push <remote name> <branch> 

# Push commits to the current working branch (short syntax)
git push

# Overwrite all commits
git push -f
```

***fetch***: The fetch command is used to update (download) changes from a remote repository to the local repository but not merge them into the current branch.
```
git fetch
```

***pull***: The pull command is understood as an improvement of the fetch command. After performing the function as the fetch command, it will automatically merge into the current branch.
```
git pull <remote name> <branch>
```

***Branch and Branches***: "Branch" means referring to a branch of a repository. A repository can have multiple branches.
```
# Create a new branch
git branch <branch name>

# create a new branch and switch to this branch
git checkout -b <branch name>

# switch to existing branch
git checkout <branch name>

# display all branches
git branch
```

***merge***: The merge command is used to merge changes from one branch to the current branch.
```
git merge <branch name>
```

