qt_env = Environment(
    tools=['default', 'qt5'],
    QT5DIR='/usr'
    
)
qt_env['QT5_DEBUG'] = 1

qt_env.EnableQt5Modules(['QtCore', 'QtWidgets', 'QtNetwork'])
qt_env.Append(CCFLAGS=['-fPIC', '-std=c++11'])

Export('qt_env')

SConscript(['src/SConscript', 'test/unit/SConscript'])

