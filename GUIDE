

## 目录结构

    PROJECT-NAME/
        README
        AUTHORS
        LICENSE
        src/
        doc/



### README

GitHub 支持多种[轻量级标记语言][][^github-markup]。README 文件请采用其中一种，并在文件名后面加上相应的后缀。

README 文件内容包括项目介绍、如何安装、如何使用。

README 文件以“`项目名 - 项目简介`”为标题，在第一部分写上项目介绍，并列出相关链接。会根据链接名来获取相关链接地址。


[轻量级标记语言]: http://en.wikipedia.org/wiki/Lightweight_markup_language
[^github-markup]: https://github.com/github/markup



### AUTHORS

AUTHORS 文件列出作者及其联系方式。邮箱地址等请写在尖括号内。



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



## 打包

打包请遵循所使用的语言的惯例。

### autotools

`make dist` 生成的 release tarball 里带有 configure 和 HTML 格式的文档，允许在另外一个目录里
`configure && make && make install` ，并能成功安装。


### python distutils

`python setup.py install` 能安装成功，并能安装到 virtualenv。



