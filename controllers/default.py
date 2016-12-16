# -*- coding: utf-8 -*-
# this file is released under public domain and you can use without limitations

# -------------------------------------------------------------------------
# This is a sample controller
# - index is the default action of any application
# - user is required for authentication and authorization
# - download is for downloading files uploaded in the db (does streaming)
# -------------------------------------------------------------------------


def index():

    #txt = myfunction()
    #n =  request.args(0)
    #db = DAL('sqlite://storage.sqlite')
    #form1 = user()
    #print "index is called there"
    page_id=0
    
    print session.counter
    print "page_id from the database                  ",
    page_id =  db(db.currentAnnotation.id > 0 ).select()[0].currentPairNumber
    page_id = page_id + 1    	
    db(db.currentAnnotation.id > 0 ).delete()
    db.currentAnnotation.insert(currentPairNumber = page_id)
    
    session.counter = (session.counter or 0) + 1
    print page_id
    print "the session counter is      ",
    print session.counter

##################################################
    #if page_id not in visited:
     #   visited.append(page_id)
###################################################

    url1, url2 = fetch_file(page_id)
    txt = folder(url1)
    ##print 'concatenating'
    ##print url1,url2
    #form.vars.Filenames.default = url1+'~~'+url2
    request.filename = url1 + '_' + url2
    #db.child.Filenames.default = url1+'~~'+url2
    #print "$$$$$$$$$$$$$$$$    ",
    #db.define_table('person', Field('name'))

    form = SQLFORM(db.child)
    if form.process().accepted:
        response.flash = 'record inserted'
        form.vars.Filenames = url1 + url2
        print db(db.child.id == form.vars.id ).update(Filenames = request.filename)
        #print form.vars
        #db = DAL('sqlite://storage.sqlite', pool_size=0)

    return dict(form=form, txt=txt, page_id=page_id, url1=url1, url2=url2 , counter = session.counter)
#     return dict(form=form, page_id=page_id)


def user():
    return dict(form=auth())

import os

import numpy as np
import csv
global lists_1, lists_2
with open('/home/yasaswi/web2py/applications/dummy/private/list1.csv', 'rb') as f:
    reader = csv.reader(f)
    lists_1 = list(reader)
#print "reading l1"
lists_1 = np.reshape(lists_1, (len(lists_1),))

with open('/home/yasaswi/web2py/applications/dummy/private/list2.csv', 'rb') as f:
    reader = csv.reader(f)
    lists_2 = list(reader)

lists_2 = np.reshape(lists_2, (len(lists_2),))


def fetch_file(page_id):
    #lists = ['s1.c', 's2.c', 's3.c']
    #lists_1 = ['s1.c', 's2.c', 's4.c', 's5.c', 'end.c']#, 's5.c', 's4.c', 's8.c', 's7.c', 's6.c']
    #lists_2 = ['s4.c', 's2.c', 's1.c', 's5.c', 'end.c']#, 's8.c', 's4.c', 's6.c', 's7.c', 's5.c']
    #datapath = os.path.join(request.folder, 'static/programs')
    url1 = lists_1[page_id]
    url2 = lists_2[page_id]
    create_frames(url1)
    create_frames(url2)
    #print url1
    #print url2
    return url1, url2


def create_frames(url):
   # print "url is             ",
    #print url
    with open(os.path.join(request.folder, "/".join(URL('static/programs',url).split('/')[2:])), 'r') as f:
        contents = f.read()
    frame_file = CODE(contents)

    with open(os.path.join(request.folder, "/".join(URL('static/programs',url.split('.')[0]+'.html').split('/')[2:])), 'w') as g:
        g.write(str(frame_file))

def folder(url):
    #page_id=1
    filename = url
    x = open(os.path.join(request.folder, 'static/programs',filename))
    file_contents = x.read()#.replace('<','&lt').replace('\n','<br>').replace('\t', '    ')
    return file_contents
    #repr(file_contents)
    #return response.stream(filepath)
