import os
Import("env")

p = os.path.abspath('.')
pre_images = ["images/desk.jpg", "images/plant.jpg"]
images = [os.path.join(p, image) for image in pre_images]

def before_upload(source, target, env):
    for image in images:
        env.Execute("./scripts/bic -i {} -o {} -j".format(image, os.path.join(p, "data/{}.img".fromat(os.path.basename(image).split('.')[0]))))

env.AddPreAction("buildprog", before_upload)