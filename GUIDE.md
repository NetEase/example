## 目录结构

    PROJECT-NAME/
        README.md
        AUTHORS
        LICENSE
        src/
        doc/

### README.md

GitHub 支持多种[轻量级标记语言][](详见[github-markup][])，可以将纯文本转换成 HTML，README 文件使用 [markdown][] 格式来编写，并保存为 README.md，以便 github 识别。

README.md 文件内容包括项目介绍、如何安装、如何使用。

README.md 文件以“`项目名 - 项目简介`”为标题：

    example - a Short Description 
    =============================

开源站点将会根据这些信息来生成站点内容：

![project name](https://github.com/NetEase/example/raw/master/doc/images/projectname.png)

在第一部分写上项目介绍，并列出相关链接：

    This is an example project, aim to be a reference of how project source code and document should be organized.
    
     * Homepage: <http://netease.github.com/projectname>
     * Mailing list: <https://groups.google.com/group/projectname>
     * Documentation: <http://projectname.readthedocs.org>
     * Wiki: <https://github.com/netease/projectname/wiki/>
     * Issues: <https://github.com/netease/projectname/issues/>
     * Tags: java, spring

根据这些信息来获取相关链接地址：

![project detail](https://github.com/NetEase/example/raw/master/doc/images/projectdetail.png)

Tags 给项目任意打标签，如编写语言，常见的标签有 `web`、`java`、`c`、`html5`、`libary`、`plugin`。

Markdown 格式和 README.md 文件几个需要注意的地方：

 * 段落顶格开始，空格是格式定义的一部分
 * 代码段空 4 格
 * 项目简介尽可能用一句话介绍

更多 markdown 例子查看 markdown 文档源文件和生成的 HTML。

 * markdown-basics [源文件](https://github.com/NetEase/example/raw/master/doc/markdown-basics.md) [HTML](https://github.com/NetEase/example/blob/master/doc/markdown-basics.md)
 * markdown-syntax [源文件](https://github.com/NetEase/example/raw/master/doc/markdown-syntax.md) [HTML](https://github.com/NetEase/example/blob/master/doc/markdown-syntax.md)

[轻量级标记语言]: http://en.wikipedia.org/wiki/Lightweight_markup_language
[github-markup]: https://github.com/github/markup
[markdown]: http://daringfireball.net/projects/markdown/

### AUTHORS

AUTHORS 文件列出项目的作者及其联系方式：

    * Firstname Lastname <foo@bar.com> <twitter:@foo> <twitter:#foo-list> <weibo:@foo> <github:foo> <linkedin:foo> <http://foo.com>

邮箱地址和主页直接用 `<>` 包起来，其他 twitter、weibo 等按上面的例子写，站点会展示这些信息：

![authors](https://github.com/NetEase/example/raw/master/doc/images/authors.png)

### LICENSE

授权协议内容放在 LICENSE 文件里，建议在文件名后面加上相应的后缀，比如，MIT License 对应的文件名就是 
`LICENSE.mit`，BSD License 对应的文件名就是 `LICENSE.bsd`，特别的，GPL家族的建议用 `COPYING`
加上相应后缀当文件名，GPL 的文件名可以是 `COPYING.gnu`，LGPL 的文件名可以是 `COPYING.lib` 或 
`COPYING.lesser`，而 AGPL 的文件名可以是 `COPYING.affero`。

若采用多个授权协议，请在 LICENSE 文件里列出协议名称和协议文件名。协议文件名建议采用 `gpl-2.0.txt`、`mpl-2.0.txt`
这样的形式。

### src/

如果没有来自语言或者打包工具的约定和要求，源代码建议放在 `src/` 目录下。

### doc/

建议使用一种[文档生成工具][]来制作文档，并在 release 的时候生成一份 HTML 格式的文档。

[文档生成工具]: http://en.wikipedia.org/wiki/Comparison_of_documentation_generators

## 发布版本和 Git tag

按照约定，软件发布版本的时候打上 git 标签，如发布 0.1 打 v0.1 标签：

    $ git tag v0.1

并推送到 github 上：

    $ git push origin --tags

关于 git tag 的详细信息看 [git-tag][] 或者运行 `git help tag`。

[git-tag]: http://git-scm.com/book/zh/Git-%E5%9F%BA%E7%A1%80-%E6%89%93%E6%A0%87%E7%AD%BE

## 打包

打包请遵循所使用的语言的惯例。

### autotools

`make dist` 生成的 release tarball 里带有 configure 和 HTML 格式的文档，允许在另外一个目录里
`configure && make && make install` ，并能成功安装。


### python distutils

`python setup.py install` 能安装成功，并能安装到 virtualenv。

## 关于 Git

### 推荐读物

 * 《Pro Git》: <http://git-scm.com/book/zh>
 * Github 帮助页: <https://help.github.com/>

### Windows 客户端

 * Github Windows 客户端: <http://windows.github.com/>
 * msysgit: <http://msysgit.github.com/>
 * tortoisegit: <http://code.google.com/p/tortoisegit/>

### Linux 客户端

 * Debian/Ubuntu: `apt-get install git`
 * Fedora/RHEL: `yum install git`

### Mac 客户端

 * Github Mac 客户端: <http://mac.github.com/>
 * 使用 [homebrew][] 安装: `brew install git`

[homebrew]: http://mxcl.github.com/homebrew/
