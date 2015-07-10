#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Copyright 2015 flw_dream@126.com

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

import os, sys, re, uuid, string

class Project(object):
    api_files = []
    src_files = []
    prj_files = []
    prjname = 'general'
    pkgname = 'template'
    rootpath = os.path.abspath('..')
    inc_dir = 'include'
    src_dir = 'src'
    prj_dir = 'projects'
    
    def __init__(self, prjname):
        self.prjname = prjname
        dir = os.path.join(self.rootpath, self.inc_dir, self.pkgname, self.prjname)
        self.api_files = os.listdir(dir)
        dir = os.path.join(self.rootpath, self.src_dir, self.pkgname, self.prjname)
        self.src_files = os.listdir(dir)
        
        dir = os.path.join(self.rootpath, self.prj_dir, self.pkgname)
        for item in os.listdir(dir):
            if self.prjname in item:
                self.prj_files.append(item)
        
    def generate(self, des_pkgname, des_prjname):
        desdir = os.path.join(self.rootpath, self.src_dir, string.lower(des_pkgname), string.lower(des_prjname))
        if not os.path.exists(desdir):
            os.makedirs(desdir)
            
        desdir = os.path.join(self.rootpath, self.inc_dir, string.lower(des_pkgname), string.lower(des_prjname))
        if not os.path.exists(desdir):
            os.makedirs(desdir)
            
        for item in self.api_files:
            srcfile = os.path.join(self.rootpath, self.inc_dir, string.lower(self.pkgname), string.lower(self.prjname), item)
            desfile = os.path.join(self.rootpath, self.inc_dir, string.lower(des_pkgname), string.lower(des_prjname), item.replace(string.lower(self.prjname), string.lower(des_prjname), 1))
            self.__copyfile(srcfile, desfile, des_pkgname, des_prjname)
            
        for item in self.src_files:
            srcfile = os.path.join(self.rootpath, self.src_dir, string.lower(self.pkgname), string.lower(self.prjname), item)
            desfile = os.path.join(self.rootpath, self.src_dir, string.lower(des_pkgname), string.lower(des_prjname), item.replace(string.lower(self.prjname), string.lower(des_prjname), 1))
            self.__copyfile(srcfile, desfile, des_pkgname, des_prjname)
            
        for item in self.prj_files:
            srcfile = os.path.join(self.rootpath, self.prj_dir, string.lower(self.pkgname), item)
            desfile = os.path.join(self.rootpath, self.prj_dir, string.lower(des_pkgname), item.replace(string.lower(self.prjname), string.lower(des_prjname), 1))
            self.__copyfile(srcfile, desfile, des_pkgname, des_prjname)
        
    def __copyfile(self, srcfile, desfile, des_pkg, des_prj):
        src_str = open(srcfile, "rb").read()
        des_str = self.__replace(src_str, des_pkg, des_prj)
        open(desfile, 'wb').write(des_str)
        print '[generate] %s' % desfile
        
    def __replace(self, src_str, pkgname, prjname):
        ret = src_str.replace('{{pkg_name}}', pkgname)
        ret = ret.replace('{{project_name}}', prjname)
        ret = ret.replace('{{project_name_upper}}', string.upper(prjname))
        ret = ret.replace('{{project_name_lower}}', string.lower(prjname))
        ret = ret.replace('{{uuid}}', str(uuid.uuid1()))
        return ret

if __name__=="__main__":
    def inputparam(index, prompt, default='', options=None):
        if len(sys.argv) > index: 
            ret = sys.argv[index]
        else: 
            ret = raw_input(prompt)
            
        if ret == '': 
            ret = default
            
        if(options is not None and ret not in options):
            print 'select one of the options please!\n'
            ret = inputparam(index, prompt, default, options)
            
        return ret
    
    types = ['general', 'pane', 'view']
    prjtype = inputparam(1, 'select plugin type(general/pane/view)\nplugin type(default: general): ', 'general', types)
    prjname = inputparam(2, 'project name: ')
    pkgname = inputparam(3, 'package name of the new project (default: plugins): ', 'plugins')
    
    prj = Project(prjtype)
    prj.generate(pkgname, prjname)
    
    if len(sys.argv) < 3: 
        raw_input("Press <ENTER> to end.")
