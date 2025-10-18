


VariantDir("build/obj", ".", duplicate=0)


env = SConscript("godot-cpp/SConstruct")


env.Append(CPPPATH = ["src/"])


sources = Glob("build/obj/src/*.cpp")  


library = env.SharedLibrary(
    "game-0/example_gdextension/bin/libgdextension{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source = sources
)


env.NoCache(library)
Default(library)