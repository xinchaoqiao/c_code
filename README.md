进行push测试

修改了本地仓库名称master -> main

命令:

```
git branch -m master main
```

设置上游直接push

命令:

```
git push -u origin main    //其中-u意思是 --set-upstream
```

在github修改默认分支名称 main -> master(手动操作)  

在本地进行 本地仓库进行同步

修改本地仓库默认分支的 命令:

```
git branch -m oldname newname
```

```
git branch -m main master
```
