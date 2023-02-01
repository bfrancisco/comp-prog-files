Push to github repo:
    git add .
    git commit -m "mssg"
    git push 

Pull from github repo (and maybe merge):
    git fetch
    git pull
    
Fetch from github repo to local repo (and make device the main):
    git fetch origin
    git reset --hard origin/main

Clone github repo to local repo:
    git clone {https or ssh link}