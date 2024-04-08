# **PULPissimoEmbedded Project**

This `README.md` will guide you through the steps needed to collaborate on this project using Git and GitHub.

## **Table of Contents**
---

- [A. Branching Strategy](#a-branching-strategy)
  - [I. List of Branches](#i-list-of-branches)
  - [II. Nested Feature Branches](#ii-nested-feature-branches)
- [B. Guide For Team Leaders](#b-guide-for-team-leaders)
  - [Step 1: Initialize a New Project](#step-1-initialize-a-new-project)
  - [Step 2: Setup Your Team](#step-2-setup-your-team)
- [C. Guide For Team Members](#c-guide-for-team-members)
  - [I. Quick Getting Started](#i-quick-getting-started)
  - [II. Commit Message Rules](#ii-commit-message-rules)
  - [III. Essential Rules for Collaboration](#iii-essential-rules-for-collaboration)
    - [Rule 1: Keep Your Branch Up-to-Date](#rule-1-keep-your-branch-up-to-date)
    - [Rule 2: Commit and Merge Regularly](#rule-2-commit-and-merge-regularly)
    - [Rule 3: Divide Work Effectively](#rule-3-divide-work-effectively)
    - [Rule 4: Maintain the Integrity of the Master Branch](#rule-4-maintain-the-integrity-of-the-master-branch)
  - [IV. Advanced Collaboration Guide](#iv-advanced-collaboration-guide)
    - [Step 1: Clone the Repository](#step-1-clone-the-repository)
    - [Step 2: Collaborating](#step-2-collaborating)
    - [Step 3: Branches](#step-3-branches)
    - [Step 4: Making Changes](#step-4-making-changes)
    - [Step 5: Staging Changes](#step-5-staging-changes)
    - [Step 6: Committing Changes](#step-6-committing-changes)
    - [Step 7: Pushing Changes](#step-7-pushing-changes)
    - [Step 8: Opening a Pull Request](#step-8-opening-a-pull-request)
    - [Step 9: Updating Your Branch](#step-9-updating-your-branch)

## **A. Branching Strategy**
---

### **I. List of Branches**
In this project, we use the following branches:

- `master`: This branch is deployable in the development environment.
- `develop`: This is where all the development work happens. When a feature is completed, it gets merged back into this branch.
- `feature`: These branches are created from the develop branch, and are used to develop new features. Once the feature is completed, the feature branch is merged back into the develop branch.
- `release`: These branches are created from the develop branch when it's time for a new release. When the release is ready, it gets merged into both the master and develop branches.
- `hotfix`: These branches are created from the master branch if there's a critical issue in production that needs to be fixed immediately.
---
### **II. Nested Feature Branches**
If the feature is large and requires work from multiple team members, then the team leader can create a `feature` branch from the `develop` branch. Then, each team member can create their own sub-branches from this `feature` branch. Each team member works on their part of the feature in their own branch and once done, they can open a pull request to merge their changes back into the `feature` branch. Once all team members have merged their changes and the feature is complete, the team leader can open a pull request to merge the `feature` branch back into the `develop` branch.

![Branching Strategy](docs/git-branch-strategy.png)

## **B. Guide For Team Leaders**
---
### **Step 1: Initialize a New Project**
1. Create a new project/directory from the command line:
   ```bash
   mkdir ~/PULPissimoEmbedded
   cd ~/PULPissimoEmbedded
   git init
   ```
2. Go to GitHub and click the `+` button in the top right corner and select `New Repository`.
3. Fill out the `Repository name` and the `Description fields`. Keep it public, and do not "Initialize this repository with a README".
4. Click `Create repository`.
5. You'll see the setup page. These are the instructions for connecting the Repo you just created in GitHub (Remote) to the directory you created in your terminal (Local).
6. Paste the lines in the red box line by line starting with `echo…` into the terminal while you're cd'ed into the directory you just created locally.
7. This adds a `.git` folder to your repo, connects you to your remote Github Repo and also gives you a `.gitignore` file.
8. If you go to your Github Repo page, you'll see the `README.md` that you initialized with and the reference to the first commit you made.
9. Now let's get this Repo up to date. Go back to your terminal and git add, git commit, and git push:
   ```bash
   git add .
   git commit -m "[REPO INIT] PULPissimoEmbedded initialized!"
   git push
   ```

### **Step 2: Setup Your Team**
1. You're a team player, so you're going to need to add your team to your repo so they can collaborate.
2. Once your team is added as collaborators they'll be able to push, merge, and a ton of other destructive things so make sure you're only adding your teammates.
3. Click on the "Settings" tab of your repo, then "Collaborators" then search for Github users and add them by clicking "Add Collaborator".
4. They'll receive an email letting them know you added them and will be listed as a collaborator.

## **C. Guide For Team Members**
---

### **I. Quick Getting Started**

1. **Clone the Repository**: First, you need to clone the repository to your local machine. You can do this with the following command:
   ```bash
   git clone https://github.com/Dark-GreenCat/PULPissimoEmbedded.git
   cd PULPissimoEmbedded/
   ```

2. **Switch to the Develop Branch**: Since all the development work happens on the `develop` branch, switch to it:
   ```bash
   git checkout develop
   ```

3. **Pull the Latest Changes**: Make sure you have the latest changes from the `develop` branch:
   ```bash
   git pull
   ```

4. **Create a Feature Branch**: Now, you can create a new branch for your feature. Remember, each feature branch should be named in the format: `features/<name>`:
   ```bash
   git checkout -b features/your-feature-name
   ```

5. **Work on Your Feature**: At this point, you can start working on your feature. Make changes to the code, and once you're done, you can stage and commit your changes:
   ```bash
   git add .
   git commit -m "Your meaningful commit message"
   ```

6. **Push Your Changes**: After committing your changes, you need to push them to the remote repository:
   ```bash
   git push origin features/your-feature-name
   ```

7. **Open a Pull Request**: Once you've pushed your changes, you can go to the GitHub page for the repository and open a pull request. Your changes will be reviewed and then merged into the `develop` branch.

8. **Continue Developing**: Repeat step 2 - 7

---
### **II. Commit Message Rules**

> Commit messages should **follow the format** of this project.
>
> Refer this guide to see details: [Commit Message Guide](docs/commit-tag.md)
---
### **III. Essential Rules for Collaboration**

#### **Rule 1: Keep Your Branch Up-to-Date**
Before opening a pull request, ensure your `feature/...` branch is up-to-date with the `develop` branch. Pull the latest changes from `develop`, merge them into your `feature/...` branch, and resolve any conflicts.

#### **Rule 2: Commit and Merge Regularly**
Frequent commits make your code easier for other team members to follow. Regular merges help avoid significant conflicts when working with others. Make it a habit to commit your changes often and merge your branches regularly.

#### **Rule 3: Divide Work Effectively**
To minimize conflicts, different team members should work on different files or different parts of a file. This division of work helps avoid conflicts between different changes made at the same location in a file.

#### **Rule 4: Maintain the Integrity of the Master Branch**
The `master` branch is read-only and should always be deployable. All development work should happen on the `develop` branch or branches that stem from it. The `master` branch should only be updated with fully tested and reviewed code from the `develop` branch.

---
### **IV. Advanced Collaboration Guide**

#### **Step 1: Clone the Repository**
1. If you're a collaborator, go to the Github Repo page, Git Clone the project, and cd into the directory. Don't fork it! Forking will copy it in a new Repo to your Github page, but you don't want that - you want to collaborate on the same Github Repo with your teammates.
   ```bash
   git clone https://github.com/Dark-GreenCat/PULPissimoEmbedded.git
   cd PULPissimoEmbedded
   ```

#### **Step 2: Collaborating**
1. When you're using git to work on the same project with multiple people, there's one central rule you must follow:  
   > **THE MASTER BRANCH SHOULD ALWAYS BE DEPLOYABLE**.
2. The way to keep Master deployable is to create new branches for new features and merge them into Master when they're completed. In this project, `master` will be managed by team leader and team members should create new branch from `develop` branch (which is a ***copy*** of `master`) instead.

For example, if you're working on a feature to add UART communication, you would do the following:

```bash
# switch to the develop branch
git checkout develop

# pull the latest changes from develop
git pull

# create a new branch for your feature
git checkout -b feature/uart_communication
```

Now, you can work on your feature in the `feature/uart_communication` branch without affecting the `develop` branch.

#### **Step 3: Branches**
1. To start, branches should always represent features. For example, if you want to add the ability for UART communication you should probably create a branch called "uart_communication" and in that branch you should only update what you need to enable UART protocol.

Here's an example of how you might do this:

```bash
# create a new branch for uart communication
git checkout -b feature/uart_communication

# make changes to the code to add uart communication

# stage the changes
git add .

# commit the changes
git commit -m "Add uart communication"

# push the changes to your branch
git push origin feature/uart_communication
```

Now, your changes are in the `feature/uart_communication` branch on the remote repository.

#### **Step 4: Making Changes**
1. Open the files in your favorite text editor and start making changes.
2. Once you've made some changes, you can check the status of your changes by running:
   ```bash
   git status
   ```
   This will show you the files that have been modified.

#### **Step 5: Staging Changes**
1. After making changes, you need to stage those changes. You can do this by running:
   ```bash
   git add .
   ```
   This command stages all the changes you've made.

#### **Step 6: Committing Changes**
1. After staging your changes, you need to commit them. You can do this by running:
   ```bash
   git commit -m "Your meaningful commit message"
   ```
   This command commits your changes with a message describing what you've done.

#### **Step 7: Pushing Changes**
1. After committing your changes, you need to push them to the remote repository. You can do this by running:
   ```bash
   git push origin feature/your-branch-name
   ```
   This command pushes your changes to the branch you're currently working on.

#### **Step 8: Opening a Pull Request**
1. After pushing your changes, you need to open a pull request. This can be done on the GitHub page for the repository.
2. Click on "Pull request" and then "New pull request". Select your branch from the dropdown and click "Create pull request".

#### **Step 9: Updating Your Branch**
1. If there have been changes in the `develop` branch while you were working on your feature, you'll need to update your branch before you can merge it into `develop`.
2. Here's how you can do that:

```bash
# switch to the develop branch
git checkout develop

# pull the latest changes from the remote develop branch
git pull origin develop

# switch back to your feature branch
git checkout feature/your-branch-name

# rebase your feature branch onto develop
git rebase develop
```

During the rebase, if there are any conflicts between your changes and the changes that have been made on the `develop` branch, Git will pause and allow you to resolve those conflicts. Once you've resolved all conflicts, you can continue the rebase with `git rebase --continue`.

After the rebase, your feature branch will be up to date with the `develop` branch, and you can create a pull request as usual.

