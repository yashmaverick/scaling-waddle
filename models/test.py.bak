# -*- coding: utf-8 -*-
from gluon.tools import Auth
auth = Auth(db)
auth.define_tables(username=True)

db = DAL("sqlite://storage.sqlite")
db.define_table('child',
     Field('Filenames', type='string' , default=request.now) ,
     Field('Label', requires=IS_IN_SET(['Copy', 'Partial Copy', 'Not Copy']),  widget=SQLFORM.widgets.radio.widget))
     #Field('Type', requires=IS_IN_SET(['Code Injection', 'Code Substitution', 'Other', 'None']),  widget=SQLFORM.widgets.radio.widget), redefine=True)

db.child.Label.reqires=IS_NOT_EMPTY()
#db.child.Type.reqires=IS_NOT_EMPTY()


db.define_table('currentAnnotation' , Field('currentPairNumber' , type='integer' , default = 0))
