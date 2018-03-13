try:
    from panda3d.openvr import *
    has_openvr = True
except:
    has_openvr = False

if not has_openvr:
    raise Exception('This feature is unsupported. Please recompile Panda3D with OpenVR support')

class OpenVRManager():
    """
    Manages the required componets to run Panda3d with OpenVR
    """

    def __init__(self):
        self.vr_system = OpenVRSystem.get_global_ptr()

        base.taskMgr.add(self.__dataLoop, 'vr-dataLoop', sort = -50)

    @property
    def initialized(self):
        """
        Returns true if the OpenVRSystem is initialized
        """
        return self.vr_system.initialized

    def initialize(self):
        """
        Initializes the OpenVR system
        """
        self.vr_system.init()

    def __dataLoop(self, task):
        """
        Processes the repeating loop tasks to manage a OpenVR setup
        """

        # Verify the OpenVRSystem is ready
        if not self.initialized:
            return

        self.vr_system.update()
        
        return task.cont
