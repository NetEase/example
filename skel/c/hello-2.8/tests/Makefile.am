# Makefile for hello/tests.
#
# Copyright 1996, 2005, 2006, 2007, 2008, 2010 Free Software Foundation, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

TESTS = greeting-1 greeting-2 hello-1 last-1 traditional-1

EXTRA_DIST = $(TESTS)

TESTS_ENVIRONMENT = top_srcdir=$(top_srcdir) PATH=.$(PATH_SEPARATOR)../src$(PATH_SEPARATOR)$$PATH \
		    HELLO=`echo hello|sed '$(transform)'` \
		    $(SHELL)
